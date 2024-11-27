#include "libguesser.h"

/** @file libnamegen.c
 * Implementation
 */

void guesser(bool roman)
{
	int beg = 50, end = 100;
	char *answer = NULL;
	size_t len = 0;
	int tmp = 0;
	
	printf("Think of a number from 1 to 100.\n");
	
	while(beg < end)
	{
		if (!roman)
		{
			printf("Is your number bigger than %d?\n", beg);
		}
		else
		{
			char str_num[4], str_num_roman[20];
			sprintf(str_num, "%d", beg);
			to_roman(str_num, str_num_roman);
			printf("Is your number bigger than %s?\n", str_num_roman);
		}
		if (getline(&answer, &len, stdin))
		{
			answer[strlen(answer) - 1] = '\0';
			if (strcmp(answer, "yes") == 0)
			{
				beg += (end - beg + 1) / 2;
			}
			else if (strcmp(answer, "no") == 0)
			{
				tmp = beg;
				beg -= (end - beg + 1) / 2;
				end = tmp;
			}
			else
			{
				printf("Don't undersand you!\n");
			}
		}
		else
		{
			printf("Don't undersand you!\n");
		}
	}
	
	if (!roman)
	{
		printf("Your number is %d!\n", beg);
	}
	else
	{
		char str_num[4], str_num_roman[20];
		sprintf(str_num, "%d", beg);
		to_roman(str_num, str_num_roman);
		printf("Your number is %s!\n", str_num_roman);
	}

	free(answer);	
}

void to_roman(char* arab, char* roman)
{
	strcpy(roman, roman_table[atoi(arab)]);
}

void to_arabic(char* rom, char* arab)
{
	for (int i = 0; i < 101; ++i)
	{
		if (!strcmp(rom, roman_table[i]))
		{
			char str_num[4];
			sprintf(str_num, "%d", i);
			strcpy(arab, str_num);
			return;
		}
	}
	printf("Can't translate the number!\n");
}
