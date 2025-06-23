#include <stdio.h>
#include <dlfcn.h>  
#include "static_global.h"

int main()
{
	void 	*handle;
	void 	*handle2;
	char 	*error;
	void	(*foo)(void);
	void	(*foo2)(void);
	
	handle = dlopen("./libdynamic.so", RTLD_LAZY);
	if (!handle)
	{
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}
	
	dlerror();
	
    	foo = (void (*)(void))dlsym(handle, "Foo");
    	
    	foo();
    	
    	dlclose(handle);	
    	
    	handle2 = dlopen("./libdynamic2.so", RTLD_LAZY);
	if (!handle2)
	{
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}
	
	dlerror();
	
	if ((error = dlerror()) != NULL) 
	{
        	fprintf(stderr, "%s\n", error);
        	dlclose(handle);
        	return 1;
    	}
	
	foo2 = (void (*)(void))dlsym(handle2, "Foo2");
	
	foo2();
	
	dlclose(handle2);
	
	return 0;	
}




