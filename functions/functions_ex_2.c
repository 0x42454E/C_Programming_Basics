/**
 * This program sets the terminal to non-canonical mode to read characters
 * one by one without waiting for Enter, and disables echoing.
 * It reads characters in a loop, prints a message for 'A' or 'T' key presses,
 * and exits cleanly when the ESC key (27) is pressed, restoring terminal settings.
 * 
 * Author: Ben
 * Date: 2024-08
 */

#include <stdio.h>  /* getchar, printf */
#include <stdlib.h> /* system, exit */

int main()
{	
	int c;
	
	system("stty -icanon -echo\n");
	
	
	while(1)
	{
		
		c = getchar();
		
		if('A' == c)
		printf("A-pressed\n");
		else if('T' == c)
		printf("T-pressed\n");
		else if(27 == c)
		{
		system("stty icanon echo");
		exit(1);
		}
		
		/*switch(c)
		{
			case 'a':
			printf("A-pressed\n");
			break;
			
			case 'A':
			printf("A-pressed\n");
			break;
			
			case 't':
			printf("T-pressed\n");
			break;
						
			case 'T':
			printf("T-pressed\n");
			break;
			
			case 27:
			system("stty icanon echo");
			exit(1);
			break;
			
			
		}*/
	
	}
	
	return 0;
}
