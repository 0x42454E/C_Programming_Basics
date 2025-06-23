/***********************************************************
 * signals_ex_4.c
 * Demonstrates inter-process signaling using `siginfo_t` and `sigwait`.
 * The process waits for SIGUSR2 with additional data (PID) sent via `sigqueue`,
 * prints "Ping", and responds by sending SIGUSR1 back to the originating PID.
 */

#define _POSIX_C_SOURCE 199309L  /* for usage of that are outside of the standard C library */
#include <stdio.h>     /* printf sscanf */
#include <signal.h>    /* sigset kill sigwait getpid */
#include <sys/types.h> /* sigset_t */
#include <signal.h>    /* sigqueue */
#include <stdlib.h>    /* abort */

sigset_t       signalSet;



void handler(int sig, siginfo_t *info, void *context) 
{
   	int value = info->si_value.sival_int;
   	if (sig == SIGUSR2)
	{
		printf("Ping\n");
		kill(value, SIGUSR1);
	}
}

int main() 
{	
	int err = 0;
	
	sigset(SIGUSR2, handler, NULL);
	
	err = sigwait(&signalSet, SIGUSR2);
    
   	if (err)
        abort();
        
   	return 0;
}
