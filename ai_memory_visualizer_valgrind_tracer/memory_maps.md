# Memory Analysis — AI Memory Visualizer

## Table of Contents
1. [Stack vs Heap — Key Differences](#stack-vs-heap)
2. [stack_example.c — Analysis](#stack-analysis)
3. [aliasing_example.c — Analysis](#aliasing-analysis)
4. [AI Error Documentation](#ai-error)

---

## Stack vs Heap — Key Differences <a name="stack-vs-heap"></a>

| Property | Stack | Heap |
|----------|-------|------|
| Allocation | Automatic | Manual (malloc/calloc) |
| Deallocation | Automatic (function exit) | Manual (free) |
| Size | Limited (~8MB) | Large (RAM dependent) |
| Speed | Fast | Slower |
| Lifetime | Until function returns | Until free() is called |
| Risk | Stack overflow | Memory leak, dangling pointer |

---

## 1. stack_example.c <a name="stack-analysis"></a>

### Program behavior
The program calls `walk_stack(0, 3)` recursively until depth 3,
then unwinds back to depth 0.

### Stack frames during execution

```
HIGH ADDRESSES
─────────────────────────────────────
| main()                             |
|   (no local variables relevant)    |
─────────────────────────────────────
| walk_stack(depth=0)                |
|   marker    = 0    addr: 0x...516c |
|   local_int = 100  addr: 0x...5134 |
|   local_buf = "A"  addr: 0x...5120 |
|   p_local   = 0x...5134 (= &local_int) |
─────────────────────────────────────
| walk_stack(depth=1)                |
|   marker    = 10   addr: 0x...513c |
|   local_int = 101  addr: 0x...5104 |
|   local_buf = "B"  addr: 0x...50f0 |
|   p_local   = 0x...5104            |
─────────────────────────────────────
| walk_stack(depth=2)                |
|   marker    = 20                   |
|   local_int = 102                  |
|   local_buf = "C"                  |
─────────────────────────────────────
| walk_stack(depth=3)                |
|   marker    = 30                   |
|   local_int = 103                  |
|   local_buf = "D"                  |
LOW ADDRESSES
─────────────────────────────────────
```

### Observed addresses from execution

```
depth=0 : &marker = 0x7ffc3ea4516c  (highest)
depth=1 : &marker = 0x7ffc3ea4513c
difference = 0x30 = 48 bytes per frame
```

### Variable lifetimes

| Variable | Created | Destroyed |
|----------|---------|-----------|
| marker | walk_stack() entry | walk_stack() return |
| local_int | dump_frame() entry | dump_frame() return |
| local_buf | dump_frame() entry | dump_frame() return |
| p_local | dump_frame() entry | dump_frame() return |

### Pointer aliasing in stack_example

```c
int local_int = 100 + depth;
int *p_local = &local_int;

// p_local and &local_int are IDENTICAL
// Confirmed by execution output:
// &local_int = 0x7ffc3ea45134
// p_local    = 0x7ffc3ea45134  <- same address
```

### Key observation
- Stack grows toward LOWER addresses (confirmed by execution)
- Each frame occupies exactly 48 bytes
- p_local is a pointer alias to local_int — they share the same memory address
- When dump_frame() returns, p_local becomes a dangling pointer
  (it still holds the address of local_int, but that memory is no longer valid)

---

## 2. aliasing_example.c <a name="aliasing-analysis"></a>

### Program behavior

```
1. make_numbers(5) allocates 20 bytes on the HEAP
2. a receives the heap address
3. b = a  ->  b points to the SAME heap block
4. free(a) releases the heap block
5. b is now a dangling pointer
6. b[2] and b[3] are accessed -> undefined behavior
```

### Memory map — BEFORE free(a)

```
STACK                          HEAP
─────────────────────         ─────────────────────────────
| main()                |     | addr: 0x4a8c480           |
|   n   = 5             |     | [0]=0  [1]=11  [2]=22     |
|   a   = 0x4a8c480 ────────► | [3]=33 [4]=44             |
|   b   = 0x4a8c480 ────────► | size = 20 bytes           |
─────────────────────────     ─────────────────────────────
```

### Memory map — AFTER free(a)

```
STACK                          HEAP
─────────────────────         ─────────────────────────────
| main()                |     | addr: 0x4a8c480           |
|   a   = 0x4a8c480 ────────► | FREED MEMORY ❌           |
|   b   = 0x4a8c480 ────────► | (dangling pointer)        |
─────────────────────────     ─────────────────────────────
```

### Variable lifetimes

| Variable | Location | Created | Destroyed |
|----------|----------|---------|-----------|
| n | Stack | main() entry | main() return |
| a | Stack | main() entry | main() return |
| b | Stack | main() entry | main() return |
| *arr (heap block) | Heap | malloc() call | free(a) call |

### Pointer aliasing — precise tracking

```c
// Step 1: allocation
a = make_numbers(5);
// a = 0x4a8c480
// heap block: [0][11][22][33][44] — 20 bytes

// Step 2: aliasing
b = a;
// b = 0x4a8c480  <- SAME address as a
// NO copy of data — only the address is copied

// Step 3: free
free(a);
// heap block released
// a = 0x4a8c480 (address unchanged, but now invalid)
// b = 0x4a8c480 (dangling pointer — points to freed memory)

// Step 4: invalid access
b[2];      // reads 8 bytes inside freed block  -> INVALID READ
b[3]=1234; // writes 12 bytes inside freed block -> INVALID WRITE
```

### Valgrind output — 3 errors detected

```
Error 1: Invalid read of size 4
  Location: aliasing_example.c:42 (b[2] read)
  Address 0x4a8c488 is 8 bytes inside freed block of size 20

Error 2: Invalid write of size 4
  Location: aliasing_example.c:44 (b[3] = 1234)
  Address 0x4a8c48c is 12 bytes inside freed block of size 20

Error 3: Invalid read of size 4
  Location: aliasing_example.c:45 (printf b[3])
  Address 0x4a8c48c is 12 bytes inside freed block of size 20
```

### Heap summary

```
Total heap usage: 2 allocs, 2 frees, 1044 bytes allocated
Result: No memory leaks — but 3 invalid memory accesses
```

---

## 3. AI Error Documentation <a name="ai-error"></a>

### Context
During analysis of aliasing_example.c, the AI generated the following
explanation about the value of b[2] after free(a):

### What the AI said (incorrect)
> "After free(a), accessing b[2] will return garbage values
> because the memory has been released. The value will be
> unpredictable and meaningless."

### Why this was wrong

The AI assumed the behavior would ALWAYS produce garbage values.
This is incomplete and misleading for two reasons:

**Reason 1 — Without Valgrind:**
```
Execution output:
  reading b[2] = -1621487654   <- garbage value (unpredictable)
```

**Reason 2 — With Valgrind:**
```
Execution output:
  reading b[2] = 22            <- original value preserved!
```

Valgrind intercepts memory operations and protects freed blocks,
which causes the original value (22) to remain readable.
Without Valgrind, the OS may have already reused that memory,
producing completely different garbage values.

### Correction
The correct explanation is:

> "After free(a), accessing b[2] produces UNDEFINED BEHAVIOR.
> The actual value depends on the execution environment:
> - Without Valgrind: the OS may reuse the memory immediately,
>   producing garbage values (-1621487654 observed)
> - With Valgrind: freed memory is protected, so the original
>   value (22) may still be readable
> In both cases, the access is ILLEGAL and must never be done."

### Lesson learned
AI explanations about undefined behavior are often oversimplified.
Always verify with actual execution output and Valgrind results.
Never trust "it will always do X" when undefined behavior is involved.

---

## Conclusion

| Program | Key Bug | Memory Type | Valgrind Error |
|---------|---------|-------------|----------------|
| stack_example.c | Dangling pointer after function return | Stack | N/A (no heap) |
| aliasing_example.c | Use-after-free via pointer alias | Heap | 3 invalid accesses |

### Golden Rules learned
```
1. free() releases memory but does NOT set the pointer to NULL
2. b = a copies the ADDRESS not the data
3. Always set pointer to NULL after free: b = NULL
4. Undefined behavior is truly undefined — never assume a fixed result
5. Valgrind changes program behavior — always test both ways
```