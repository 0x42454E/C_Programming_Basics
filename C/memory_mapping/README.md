# Memory Mapping and Variable Scope Example in C

This project demonstrates various C concepts including:

- Different types of variables (global, static global, static local, extern, const, weak symbols)
- Pointers to variables in different memory regions
- Recursion and stack unwinding
- Heap allocation and alignment considerations
- Use of `static` functions and variables
- Handling unused variables warnings
- Function declarations and definitions across multiple files

---

## File Overview

- `memory_mapping.h`  
  Header file declaring variables and functions with different storage classes and linkage.

- `memory_mapping.c`  
  Implements two recursive functions `MemoryMappingCode1` and `MemoryMappingCode2` with multiple local and global variables, pointers, and calls to each other.

- `main.c`  
  Entry point, calling `MemoryMappingCode1`.

---

## Key Concepts Illustrated

### Variable Types and Linkage

| Variable Type             | Example                    | Characteristics                                     |
|--------------------------|----------------------------|----------------------------------------------------|
| Global                   | `int global_var1 = 5;`     | Visible throughout program                          |
| Static Global            | `static int static_global_var1 = 11;` | Limited to translation unit                          |
| Static Local             | `static int static_local_var1 = 111;` | Retains value between calls, scope limited to function |
| Extern                   | `extern int global_var1;`  | Declared elsewhere, used across files               |
| Weak Symbol              | `int __attribute__((weak)) g_weak_symbol = 0;` | Can be overridden by strong definitions             |
| Const                    | `const int const_local = 5;` | Immutable after initialization                      |
| Static Function          | `static void StaticFunction()` | Private to file scope                               |

### Memory Areas

- **Stack:** Local variables (`int i`, `char a`), function arguments.
- **Heap:** Dynamically allocated variables via `malloc()`.
- **Data Segment:** Global and static variables.
- **Read-only Data:** String literals (`"abc"`).

---

## Function Descriptions

### `MemoryMappingCode1` and `MemoryMappingCode2`

- Recursive functions that call each other.
- Use a static variable `recursion_level` to track recursion depth.
- Decrement or check global variables to control recursion stopping.
- Declare and initialize many types of variables and pointers to demonstrate memory layout.
- Allocate memory on heap but deliberately do not free it (except in unreachable code) to analyze heap growth during debugging.
- Cancel unused variable warnings with `(void)` casts for debugging clarity.

### `StaticFunction`

- Static helper function limited to the file.
- Demonstrates use of static linkage.

### `ExternFunction`

- Extern function declaration, defined in another file.

---

## Usage Instructions

Compile the project with:

```bash
gcc -o memory_mapping main.c memory_mapping.c
