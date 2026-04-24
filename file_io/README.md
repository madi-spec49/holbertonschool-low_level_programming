# 📁 File I/O in C (Linux / Unix)

## 📌 Overview

File I/O (Input/Output) in C refers to the way programs read from and write to files using system calls provided by the operating system.

On Linux systems, file I/O is mainly handled through **system calls** such as `open`, `read`, `write`, and `close`.

---

## 🔧 Key Concepts

### 📌 File Descriptor (FD)

A file descriptor is a small integer used by the kernel to identify an open file.

| FD | Meaning |
|----|--------|
| 0  | stdin (keyboard input) |
| 1  | stdout (screen output) |
| 2  | stderr (error output) |

Any newly opened file usually starts at FD **3**.

---

## 🧠 Main System Calls

### 🔹 open()

Used to open or create a file.

```c
int open(const char *pathname, int flags);