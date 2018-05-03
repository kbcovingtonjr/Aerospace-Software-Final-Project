#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Function: getCacheSize
 * ----------------------
 *
 *   Gets the cache size of computer's processor by reading 
 *   the file /proc/cpuinfo
 *
 *   Ouputs:	cacheSize	- size of cache in Bytes
 *
 */
int getCacheSize()
{
	// Open file where CPU info is stored on linux filesystem
	FILE* file = fopen("/proc/cpuinfo", "r");

	// Loop through lines of file until we find the line that says "cache"
	char valueOnLine[300];
	while (!feof(file))
       	{
		// Read line of file
		fscanf(file, "%c", &valueOnLine);
		
		// If we found the line where the cache data field is, break
		if ( strcmp("cache", valueOnLine) == 0 )
		{
			break;
		}
       	}

	// Skip a few lines that contain some formatting
	fscanf(file, "%s", &valueOnLine);
	fscanf(file, "%s", &valueOnLine);
	fscanf(file, "%s", &valueOnLine);	// number read from file
	int cacheNum = atoi(valueOnLine);	// convert string to int
       	
	// Get units of cache size
	char units[100];
	fscanf(file, "%s", &units);		// units of cache size
	int cacheSize;				// number of bytes of cache

	if ( strcmp("B", units) == 0 )
	{
		cacheSize = cacheNum;
	}
	else if ( strcmp("KB", units) == 0 )
	{
		cacheSize = cacheNum * 1024;
	}
	else if ( strcmp("MB", units) == 0 )
	{
		cacheSize = cacheNum * 1024 * 1024;
	}

	fclose(file);		// close file
	return cacheSize;	// number of bytes of cache
}
