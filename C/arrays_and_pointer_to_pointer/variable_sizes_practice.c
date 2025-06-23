#include <stdio.h> /* printf */

/**
 * This program prints the size of common C types including char, short, int, long, float, double, and long double,
 * along with their signed and unsigned variations. It helps demonstrate how data type sizes can vary across systems.
 *
 * Useful for learning how data is represented in memory and understanding platform-specific behavior in C.
 *
 * Author: Ben
 * Date: 2024-08
 */

int main(void)
{
    printf("Type                        | Size (bytes)\n");
    printf("----------------------------|--------------\n");

    printf("%-28s | %lu\n", "char", sizeof(char));
    printf("%-28s | %lu\n", "signed char", sizeof(signed char));
    printf("%-28s | %lu\n", "unsigned char", sizeof(unsigned char));

    printf("%-28s | %lu\n", "short", sizeof(short));
    printf("%-28s | %lu\n", "short int", sizeof(short int));
    printf("%-28s | %lu\n", "signed short", sizeof(signed short));
    printf("%-28s | %lu\n", "signed short int", sizeof(signed short int));
    printf("%-28s | %lu\n", "unsigned short", sizeof(unsigned short));
    printf("%-28s | %lu\n", "unsigned short int", sizeof(unsigned short int));

    printf("%-28s | %lu\n", "int", sizeof(int));
    printf("%-28s | %lu\n", "signed", sizeof(signed));
    printf("%-28s | %lu\n", "signed int", sizeof(signed int));
    printf("%-28s | %lu\n", "unsigned", sizeof(unsigned));
    printf("%-28s | %lu\n", "unsigned int", sizeof(unsigned int));

    printf("%-28s | %lu\n", "long", sizeof(long));
    printf("%-28s | %lu\n", "long int", sizeof(long int));
    printf("%-28s | %lu\n", "signed long", sizeof(signed long));
    printf("%-28s | %lu\n", "signed long int", sizeof(signed long int));
    printf("%-28s | %lu\n", "unsigned long", sizeof(unsigned long));
    printf("%-28s | %lu\n", "unsigned long int", sizeof(unsigned long int));

    printf("%-28s | %lu\n", "long long", sizeof(long long));
    printf("%-28s | %lu\n", "long long int", sizeof(long long int));
    printf("%-28s | %lu\n", "signed long long", sizeof(signed long long));
    printf("%-28s | %lu\n", "signed long long int", sizeof(signed long long int));
    printf("%-28s | %lu\n", "unsigned long long", sizeof(unsigned long long));
    printf("%-28s | %lu\n", "unsigned long long int", sizeof(unsigned long long int));

    printf("%-28s | %lu\n", "float", sizeof(float));
    printf("%-28s | %lu\n", "double", sizeof(double));
    printf("%-28s | %lu\n", "long double", sizeof(long double));

    return 0;
}