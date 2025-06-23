#include <stdio.h>
#include "static_global.h"

int x = 1;

void PrintfGlobalVariableAddress()
{
	printf("%p\n", (void*)&x);
}
