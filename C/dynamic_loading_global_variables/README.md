# Dynamic Library Loading and Global Variable Access in C

This practice demonstrates how to dynamically load shared libraries at runtime using `dlopen`, `dlsym`, and `dlclose`, and how to access global variables declared in those libraries.

---

## Overview

- **main.c**  
  Loads two dynamic libraries `libdynamic.so` and `libdynamic2.so` and calls their exported functions `Foo` and `Foo2`.

- **static_global.h**  
  Header declaring an external global variable `x` and a function to print its address.

- **libdynamic (dynamic library 1)**  
  Implements function `Foo()` which prints the address of global variable `x`.

- **libdynamic2 (dynamic library 2)**  
  Implements function `Foo2()` which also prints the address of the same global variable `x`.

- **Global variable `x`**  
  Defined in `static_global.c` and shared between both libraries.

---

## Key Concepts

### Dynamic Linking with `dlopen` / `dlsym`

- `dlopen` loads a shared library into memory at runtime.
- `dlsym` obtains the address of a symbol (function or variable) from the loaded library.
- `dlclose` unloads the shared library.

### Shared Global Variables Across Libraries

- Both `libdynamic.so` and `libdynamic2.so` refer to the same global variable `x` declared in `static_global.c`.
- The function `PrintfGlobalVariableAddress()` prints the memory address of `x`, demonstrating that both libraries access the same global symbol.

---

## Compilation Instructions

Build the shared libraries:

```bash
gcc -fPIC -c static_global.c -o static_global.o
gcc -shared -o libdynamic.so dynamic1.c static_global.o
gcc -shared -o libdynamic2.so dynamic2.c static_global.o
