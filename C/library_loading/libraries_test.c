#include <stdio.h>
#include <dlfcn.h>  
#include "exe1.h"

int main()
{
	int 	a = 1;
	void 	*handle;
	int	(*Foo)(int);
	char 	*error;
	
	handle = dlopen("./libexe.so", RTLD_LAZY);
	if (!handle)
	{
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}
	
	dlerror();
	
    	Foo = (int (*)(int))dlsym(handle, "Foo");
	
	if ((error = dlerror()) != NULL) 
	{
        	fprintf(stderr, "%s\n", error);
        	dlclose(handle);
        	return 1;
    	}
    
	Foo(a);
	
	dlclose(handle);
	
	return 0;
}



