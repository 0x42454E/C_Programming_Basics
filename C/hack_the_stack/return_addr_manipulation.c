/**
 * This program demonstrates low-level manipulation of return addresses
 * using GCC built-ins (__builtin_return_address) and direct memory overwrite.
 * It attempts to hijack the return address of func2 to redirect control.
 */

#include <stdio.h> /* printf */

void func2 (void *arg) {
long f2;
printf("Enter func2\n");
long *func2_return_address = __builtin_extract_return_addr(__builtin_return_address(0)); // Return address for func2
long *func1_return_address = __builtin_extract_return_addr(__builtin_return_address(1)); // Return address for func1 (not 1, use 2)
printf("func2_return_address: %p\n", func2_return_address);
printf("func1_return_address: %p\n", func1_return_address);
*func2_return_address = *func1_return_address; // Modify return address
printf("func2_return_address after: %p\n", func2_return_address);
printf("func1_return_address after: %p\n", func1_return_address);
printf("Exit func2\n");
}

void func1()
{
long f1; printf ("Enter funcl\n");
func2 (&f1) ;
printf ("Exit func1\n");
}

int main ()
{
const long x=1; long y=5;
*(long *)(&y + 1) = 1337;
printf ("x=%lu\n", x) ;
func1();
printf ("Exit main\n");
return 0;
}
