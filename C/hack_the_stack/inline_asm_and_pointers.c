/**
 * Low-level C program demonstrating pointer manipulation,
 * stack frame control via inline assembly, and pthread cancellation.
 * 
 * Author: Ben  
 * Reviewed by: Chananya  
 * Date: 2024-10  
 * 
 */

#include <stdio.h>      /* printf, fflush */
#include <signal.h>     /* kill, SIG constants */
#include <stdint.h>     /* fixed-width integers */
#include <pthread.h>    /* pthread_self, pthread_cancel */
#include <stdlib.h>     /* standard utilities */


void func2(void *arg)
{
	long f2;

	printf("Enter func2\n");
	
	/* AREA2 */
	
	printf("Exit func2\n");

	pthread_cancel(pthread_self());
	
	
	fflush(stdout);

	/*lseek(fp, SEEK_CUR, SEEK_END - 20);*/
	
	  __asm__ __volatile__(
        "mov %%rbp, %%rsp\n" 
        "pop %%rbp\n"        
        :                    
        :                    
    );

	/*int pid;*/
	/*pid = fork();
	
	if (!pid)*/
	/*kill(getpid(), sigreturn);*/

}

void func1()
{
	long f1;
	
	printf("Enter func1\n");

	func2(&f1);
	
	printf("Exit func1\n"); /* delete this part */
}

int main()
{
	const long 	x = 1;
	long 		y = 5;
	
	
	/* AREA1 */
	
	/***************************
	 * 	-- 1 --
	 *	*(long*)&x = 1337; 
	 */
	
	
	/***************************
	 * 	-- 2 --
	 * long *ptr = &y;
	 *
	 *	y = 1337;
	 *
	 *	ptr += 1;
	 *	  
	 *	*ptr = 1337;
	 */
	

	

	
	
	printf("x = %lu\n", x);
	func1();

	
	/*long pos = ftell(fp);
	printf("%lu\n", pos);*/
	printf("Exit main\n");
	return 0;
}
