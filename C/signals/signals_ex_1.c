/* 
 * Demonstrates inter-process communication using UNIX signals.
 * The child waits for SIGUSR1, then responds by sending SIGUSR2 to the parent.
 * Both parent and child have signal handlers to print confirmation messages.
 */

#define _POSIX_SOURCE
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>


void parent_handler(int sig) 
{
	if (sig == SIGUSR2)
	{
		printf("sigusr2 recieved in parent\n");
	}
}


void child_handler(int sig) 
{
	if (sig == SIGUSR1)
	{
		printf("sigusr1 recieved in child\n");
		kill(getppid(), SIGUSR2);
	}
}


int child_function(void)
{
	
	while(1)
	{
		printf("waiting..(child_function)\n");
		sigpause(SIGUSR1);
	}
		
	return 0;	
}


