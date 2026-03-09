# Dynamic Memory Allocation in C — malloc & calloc

## What is Dynamic Memory Allocation?

In C, memory can be allocated in two ways:

- **Static** — size fixed at compile time (e.g., `int arr[10]`)
- **Dynamic** — size decided at runtime using `malloc` or `calloc`

---

## malloc

### Prototype
```c
#include <stdlib.h>
void *malloc(size_t size);
```

### How it works

`malloc` reserves a block of memory of `size` bytes and returns a pointer to it.
The memory is **not initialized** — it contains garbage values.

### Example
```c
int *p = malloc(sizeof(int) * 5);  // reserves 5 integers = 20 bytes

if (p == NULL)   // always check!
    return (1);

p[0] = 42;
free(p);         // always free!
```

### sizeof reference

| Type | Size |
|------|------|
| `char` | 1 byte |
| `short` | 2 bytes |
| `int` | 4 bytes |
| `long` | 8 bytes |
| `float` | 4 bytes |
| `double` | 8 bytes |
| `pointer *` | 8 bytes |

### malloc calculations

| Statement | Calculation | Result |
|-----------|-------------|--------|
| `malloc(10)` | 10 | **10 bytes** |
| `malloc(sizeof(char) * 10)` | 1 x 10 | **10 bytes** |
| `malloc(sizeof(char) * 10) + 1)` | (1 x 10) + 1 | **11 bytes** |
| `malloc(sizeof(int) * 10)` | 4 x 10 | **40 bytes** |
| `malloc(sizeof(int) * 4)` | 4 x 4 | **16 bytes** |
| `malloc(sizeof(unsigned int) * 2)` | 4 x 2 | **8 bytes** |

---

## calloc

### Prototype
```c
#include <stdlib.h>
void *calloc(size_t nmemb, size_t size);
```

### How it works

`calloc` reserves memory for `nmemb` elements of `size` bytes each.
Unlike `malloc`, it **initializes all bytes to 0**.

### Example
```c
int *p = calloc(5, sizeof(int));  // 5 integers, all set to 0

if (p == NULL)
    return (1);

free(p);
```

---

## malloc vs calloc

| | `malloc` | `calloc` |
|---|---|---|
| Arguments | 1 (total size) | 2 (nmemb, size) |
| Initialization | ❌ garbage values | ✅ zeros |
| Speed | faster | slightly slower |
| Usage | general purpose | arrays, buffers |

---

## Golden Rules

```
1. Always check if malloc/calloc returns NULL
2. Always free() memory when done
3. Never use memory after free()
4. Use sizeof() instead of hardcoded sizes
```

### Good practice
```c
int *p = malloc(sizeof(int) * 10);  // 1. allocate

if (p == NULL)                       // 2. check
    return (1);

p[0] = 42;                          // 3. use

free(p);                            // 4. free
p = NULL;                           // 5. secure
```

---

## Valgrind — Memory checker

```bash
# Compile with debug info
gcc -g programme.c -o programme

# Run with Valgrind
valgrind ./programme
```

### Common errors detected

| Error | Meaning |
|-------|---------|
| `definitely lost` | malloc without free |
| `invalid read` | reading forbidden memory |
| `invalid write` | writing out of bounds |
| `use after free` | using freed memory |

---

*README written in Markdown — Dynamic Memory Allocation*