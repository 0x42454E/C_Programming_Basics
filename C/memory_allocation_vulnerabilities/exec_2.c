/*
 * This program allocates a 64-byte buffer and copies a user-provided string into it.
 *
 * - It uses `calloc` to allocate zero-initialized memory for the buffer.
 * - The input is copied into the buffer using `strcpy`, which assumes the input fits.
 * - Then it prints the contents of the buffer.
 *
 * - No bounds checking is performed on `argv[1]`.
 * - If the input is larger than 63 characters, it  cause a buffer overflow.
 * - This makes the program vulnerable and unsafe for untrusted input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char* buffer = calloc(64, sizeof(*buffer));
	
	if (!buffer)
	{
		printf("Allocation failed\n");
		return -1;
	}
	
	strcpy(buffer, argv[1]);
	
	printf("%s\n", buffer);
	
	return 0;
}
