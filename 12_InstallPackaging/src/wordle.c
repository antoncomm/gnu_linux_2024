#include"wordle.h"
#include "config.h"

/** @mainpage Guess 5-letters word using 6 attempts
 * @copydetails Wordle
 */

/** @page Wordle
 * Guess 5-letters word using 6 attempts
 * @section SYNOPSIS
 * `wordle` 
 * @section DESCRIPTION
 * Guess the Wordle in 6 tries. Each guess must be a valid 5-letter word.
 * The color of the tiles will change to show how close your guess was to the word.
 * Green means that letter in the right spot.
 * Yellow means that letter in the word but in the wrong spot.
 * Black letters are not in the word.
 */
int main(int argc, char* argv[])
{
	setlocale (LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);

	if (argc == 2 && !(strcmp(argv[1], "-h") && strcmp(argv[1], "-help")))
	{
		printf(_("Usage: %s [OPTIONS]\n"), argv[0]);
		printf(_("%s -h, --help - Help information\n"), argv[0]);
		printf(_("LC_ALL=ru_RU.UTF-8 %s - play in russian\n"), argv[0]);
	}
	
	if (Play())
	{
		return 1;
	}

	return 0;
}
