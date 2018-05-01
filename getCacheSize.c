#include <stdio.h>
#include <string.h>

int main( int argc, char* argv[] )
{
	
	int cacheSize;	// number of byte of cache

	// Open file where CPU info is stored on linux filesystem
	FILE* file = fopen("/proc/cpuinfo", "r");

	// Get cache size
	char valueOnLine[300];
	while (!feof(file))
       	{
		fscanf(file, "%s", &valueOnLine);
		
		if ( strcmp("cache", valueOnLine) == 0 )
		{
			break;
		}
       	}
	fscanf(file, "%s", &valueOnLine);
	fscanf(file, "%s", &valueOnLine);
	fscanf(file, "%s", &valueOnLine);
	printf("%s\n", valueOnLine);
       	
	// Get units of cache size
	char units[100];
	fscanf(file, "%s", &units);
	printf("%s\n", units);
	if ( strcmp("KB", valueOnLine) == 0 )
	{
		cacheSize = 
	}

	return 0;

}
