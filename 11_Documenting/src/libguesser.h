#include <stdbool.h>
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#include "table.h"

/** @mainpage Numbers guesser
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

/** @page library Numbers guesser
 * This is free and unencumbered software released into the public domain.
 *
 * Guess() function guess a number from 1 to 100.
 *
 */

/** Guess number from 1 to 100
 *
 * @param roman Use roman number 
 */
void guesser(bool roman);

/** Translate number from arabic to roman
 *
 * @param arab String version of arabic number
 * @param rom Roman number after translation (you should allocate memory for roman number)
 */
void to_roman(char* arab, char* rom);

/** Translate number from roman to arabic
 *
 * @param rom String version of roman number
 * @param arab Arabic number after translation (you should allocate memory for arabic number)
 */
void to_arabic(char* rom, char* arab);
