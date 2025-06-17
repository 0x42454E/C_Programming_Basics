/**
 * This program prints numbers in a given range that do not contain the digit '7'
 * and are not divisible by 7. If the number contains '7' or is divisible by 7, it prints "BOOM".
 * 
 * Author: Ben
 * Date: 2024-08
 */

#include <assert.h>  /* assert */
#include <stdlib.h>  /* malloc, free */
#include <string.h>  /* strchr */
#include <stdio.h>   /* printf, scanf */


void Poli(unsigned from, unsigned to);
char *ArrCast(unsigned n);

int main()
{
	unsigned start, end;
	
	printf("input the desired start range value:");
	scanf("%u", &start);
	printf("input the desired end range value:");
	scanf("%u", &end);
	
	Poli(start, end);
	
	return 0;
}

void Poli(unsigned from, unsigned end)
{
	unsigned i = from, test, j = 0;
	unsigned *s = malloc((end - from + 1) * sizeof(unsigned));
	char ch = '7', *ptr, *ptr2;
	
	while((end - from) > j)
	{
		s[j] = i++;
		++j;
	}
	
	j = 0;
	i = from;	
	
	while((end - from + 1) > j)
	{

		test = s[j] % 7;
		
		ptr = ArrCast(s[j]);
		
		ptr2 = strchr(ptr, ch);
		++j;
		
		if(ptr2 == NULL && 0 != test) 
		{
			printf("%u\n", s[j - 1]);
			continue;
		}

		printf("BOOM\n");
		
		
		free(ptr);
	}
	
	free(ptr); /* not sure if nessecary */
	free(s);
}

char *ArrCast(unsigned n)
{
	unsigned temp = n, count = 0;
	char *p;
	
	   do
	  {
  		  temp /= 10;
  		  ++count;
  		  
 	  } 	while (temp != 0);
 	  
 	  temp = n;
 	  
 	  p = malloc((count + 1) * sizeof(char));
  	  p[count] = '\0';
  	  
  	  while(0 < count)
  	  {
  	  	  p[--count] = (char)(temp % 10 + '0');
  	  	  temp /= 10;
  	  }
  	  
  	return p;
}
