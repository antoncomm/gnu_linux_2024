#include "stdio.h"  
#include <dlfcn.h>
#include "string.h"

typedef int (*remove_type)(const char * restrict);

int remove(const char *fname)
{
	if (strstr(fname, "PROTECT"))
	{
		printf("Can't delete protect file!\n");
		return 0;
	}
	return ((remove_type)(dlsym(RTLD_NEXT, "remove")))(fname);
}
