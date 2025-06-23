# 📚 Dynamic and Static Library Linking in C

This project demonstrates both **static** and **dynamic** linking in C using a simple math library (`math_functions.c`). It also includes an example of runtime dynamic loading using `dlopen()` and `dlsym()` from `libdl`.

---

## 📁 Project Structure

main.c # Main program for linking with static/dynamic lib
main_explicit.c # Main program using dlopen/dlsym
math_functions.c # Source of math functions
math_functions.h # Header for math functions
libmath.a # Static library (generated)
libmath.so # Dynamic library (generated)



---

## 📦 Static Library

### 🔨 Build the static library

```bash
gcc -c math_functions.c -o math_functions.o
ar rcs libmath.a math_functions.o

 Compile & link with static library

gcc main.c -L. -lmath -o myprogram
-L.: Search in current directory

-lmath: Links libmath.a


Dynamic Library
🔨 Build the shared (dynamic) library
bash
Copy
Edit
gcc -c -fPIC math_functions.c -o math_functions.o
gcc -shared -o libmath.so math_functions.o

Compile & link with dynamic library (implicitly)

gcc -o myprogram main.c -L. -lmath

Set runtime library path before running:
export LD_LIBRARY_PATH=.

 Dynamic Loading with dlopen
🔨 Compile with dynamic linking explicitly

gcc -o myprogram_explicit main_explicit.c -ldl
-ldl: Links to dynamic loader
