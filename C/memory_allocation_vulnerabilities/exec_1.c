/*
 * This program demonstrates a simple password check using `gets()` (unsafe).
 *
 * - The real password is stored in a buffer called `password`.
 * - User input is stored in `buff`, then compared to `password` using `strncmp`.
 * - If they match, access is granted.
 *
 */

#include <string.h>
#include <stdio.h>

int main()
{
	char password[20] = "this is my password";
	char buff[20] = "";
	gets(buff);
	
	printf("password is %s",password);
	printf("buff is %s",buff);
	
	if (0 == strncmp(buff, password, 20))
	{
		printf("You have successfully entered the password.\n");
	}
	else
	{
		printf("Sorry, your password is incorrect.\n");
	}
	
	return 0;
}


