#include <stdio.h>
#include <stdbool.h>
#include "libguesser.h"

/** @page guesser
 * The number guesser from 1 to 100 
 * @section SYNOPSIS
 * `guesser` [\a options]
 * @section DESCRIPTION
 * Guess number from 1 to 100. You can use roman numbers, if you want.
 * @section OPTIONS
 * -r - use roman numbers
 * -h, --help - help information
 * @copydetails library
 */
int main(int argc, char* argv[])
{
	if (argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) 
	{
    	printf("Usage: %s [OPTION]\n", argv[0]);
        printf("  Options:\n");
        printf("  -r - use roman numbers\n");
		printf("  -h, --help - Help information\n");
		exit(EXIT_FAILURE);
	}
	bool is_roman = false;
	if (argc == 2 && !strcmp(argv[1], "-r"))
	{
		is_roman = true;
	}

	guesser(is_roman);	
	return 0;
}
