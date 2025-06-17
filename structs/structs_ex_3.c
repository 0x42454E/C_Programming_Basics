#include <stdio.h>
#include <stdlib.h>

/**
 * This program demonstrates the use of a union to handle input using getline.
 * It reads a line of input from the user, prints it, and then frees all allocated memory.
 * 
 * Author: Ben
 * Date: 2024-08
 */

union Types
{
	void 	*p;
	//int 	i;
	//float	b;
	char 	**buffer;
};

int main()
{
	union 		Types data;
	
	size_t 		len = 0;
	
	ssize_t		chars_read;
	
	
	data.buffer = malloc(sizeof(char *));
	
	*data.buffer = NULL;
	
	printf("insert desired input: \n");
	
	charsread = getline(data.buffer, &len, stdin);
	
	printf("%s", *data.buffer);
	
	free(*data.buffer);
	
	free(data.buffer);
	

	return 0;	
}
	
