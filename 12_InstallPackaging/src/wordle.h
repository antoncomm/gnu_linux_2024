#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <libintl.h>
#include <locale.h>
#include "config.h"

#define _(STRING) gettext(STRING)

#define GUESS_NUMBER 6 /**< Number of guess in the game*/
#define LEN_WORDS 5 /**< Length of words*/

/* Types of letters */
#define BLACK_LETTER 1 /*< Using black letters on white background*/
#define GREEN_LETTER 2 /*< Using green letters on white background*/
#define YELLOW_LETTER 3 /*< Using yellow letters on white background*/

/** @file wordle.h
 *	Implementation
 */

/** Print new letters after users guess.
 *
 * @param guess users word
 * @param guess_num array with information about guessed letters
 * @param row attempt number
 */
void Print_letters(const char *guess, int *guess_num, int row)
{
	for(int i = 0; i < LEN_WORDS; ++i)
	{
		if(guess_num[i] == BLACK_LETTER)
		{
			attron(COLOR_PAIR(BLACK_LETTER));
			mvwprintw(stdscr, row, i, "%c", guess[i]);
			refresh();
			attroff(COLOR_PAIR(BLACK_LETTER)); 
		}
		else if(guess_num[i] == YELLOW_LETTER)
		{
			attron(COLOR_PAIR(YELLOW_LETTER));
			mvwprintw(stdscr, row, i, "%c", guess[i]);
			refresh();
			attroff(COLOR_PAIR(YELLOW_LETTER)); 
		}
		else if(guess_num[i] == GREEN_LETTER)
		{
			attron(COLOR_PAIR(GREEN_LETTER));
			mvwprintw(stdscr, row, i, "%c", guess[i]);
			refresh();
			attroff(COLOR_PAIR(GREEN_LETTER)); 
		}
	}
	mvwprintw(stdscr, row, LEN_WORDS, "\n");
}

/** Print phrase in the end of the game.
 *
 * @param i how many attempts user use
 * @param is_guessed was the word guessed
 * @param answer true answer
 */
void Print_phrase(int i, int is_guessed, char *answer)
{
	if (!is_guessed)
	{
		mvwprintw(stdscr, GUESS_NUMBER, 0, _("Not cool. Answer was: %s\n"), answer);
		return;
	}
	switch (i)
	{
		case 1:
			mvwprintw(stdscr, i, 0, _("Coooooooooooool!\n"));
			break;
		case 2:
			mvwprintw(stdscr, i, 0, _("Coooooooool!\n"));
			break;
		case 3:
			mvwprintw(stdscr, i, 0, _("Coooool!\n"));
			break;
		case 4:
			mvwprintw(stdscr, i, 0, _("Cool!\n"));
			break;
		case 5:
			mvwprintw(stdscr, i, 0, _("Col!\n"));
			break;
		case 6:
			mvwprintw(stdscr, i, 0, _("Cl!\n"));
			break;

	}
}

/** Fill array with information about guessed letters.
 *
 * @param answer true word
 * @param guess users word
 * @param answer_num array with information about letters in answer
 * @param guess_num array with information about guessed letters
 */
void Fill_difference(const char *answer, const char *guess, int *answer_num, int *guess_num)
{
	for(int i = 0; i < LEN_WORDS; ++i)
	{
		answer_num[i] = BLACK_LETTER; guess_num[i] = BLACK_LETTER;
		if (answer[i] == guess[i])
		{
			answer_num[i] = GREEN_LETTER; guess_num[i] = GREEN_LETTER;
		}
	}

	for(int i = 0; i < LEN_WORDS; ++i)
	{
		if (guess_num[i] != GREEN_LETTER)
		{
			for(int j = 0; j < LEN_WORDS; ++j)
			{
				if(answer_num[j] == BLACK_LETTER && answer[j] == guess[i])
				{
					guess_num[i] = YELLOW_LETTER; answer_num[j] = YELLOW_LETTER;
				}
			}
		}
	}
	
}

/** Check new attempt.
 *
 * @param answer true word
 * @param guess users word
 * @param row attempt number
 */
int Check(const char *answer, const char *guess, int row)
{
	int answer_num[LEN_WORDS], guess_num[LEN_WORDS];
	
	Fill_difference(answer, guess, answer_num, guess_num);
	
	Print_letters(guess, guess_num, row);

	for(int i = 0; i < LEN_WORDS; ++i)
	{
		if(guess_num[i] != GREEN_LETTER)
		{
			return 1;
		}
	}
	return 0;
}

/** Generate word for game.
 *
 * @param word generate answer from dictionary
 */
int Generate_word(char *word)
{
	srand(time(NULL));

	char name[100] = "\0";
	strcat(name, DATADIR);
	strcat(name, "/en_dict.txt");
	FILE* file = fopen(name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "%s\n", name);
		fprintf(stderr, _("Can't open dict!\n"));
		return 1;
	}
    fseek(file, 0L, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);

	int number_row = rand() % (file_size / (LEN_WORDS + 1)); 
	fseek(file, (LEN_WORDS + 1) * number_row, SEEK_SET);

	if (fgets(word, LEN_WORDS + 1, file) == NULL)
	{
		fprintf(stderr, _("Can't get a line!\n"));
		return 1;
	}

	fseek(file, 0L, SEEK_SET);
	fclose(file);
	return 0;
}

/* Main function with game: it call word generation and check users words.
 * It also renders the answers.
 *
 */
int Play()
{
	char answer[LEN_WORDS + 1], guess[LEN_WORDS + 1];
	if (Generate_word(answer))
	{
		return 1;
	}
		
	initscr();
	cbreak();	
	start_color();
	init_pair(YELLOW_LETTER, COLOR_YELLOW, COLOR_WHITE);
	init_pair(GREEN_LETTER, COLOR_GREEN, COLOR_WHITE);
	init_pair(BLACK_LETTER, COLOR_BLACK, COLOR_WHITE);
	bkgd(COLOR_PAIR(BLACK_LETTER));

	int times = 0, is_guessed = 0;
	for (; times < GUESS_NUMBER; ++times)
	{
		getstr(guess);
		if (!Check(answer, guess, times))
		{
			is_guessed = 1;
			break;
		}
	}
	Print_phrase(times + 1, is_guessed, answer);
    getch();
	endwin();

	return 0;
}
