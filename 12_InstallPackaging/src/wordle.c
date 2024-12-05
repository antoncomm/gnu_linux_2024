#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define GUESS_NUMBER 6
#define LEN_WORDS 5

#define BLACK_LETTER 1
#define GREEN_LETTER 2
#define YELLOW_LETTER 3

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

void Print_phrase(int i, int is_guessed, char *answer)
{
	if (!is_guessed)
	{
		mvwprintw(stdscr, GUESS_NUMBER, 0, "Not cool. Answer was: %s\n", answer);
		return;
	}
	switch (i)
	{
		case 1:
			mvwprintw(stdscr, i, 0, "Coooooooooooool!\n");
			break;
		case 2:
			mvwprintw(stdscr, i, 0, "Coooooooool!\n");
			break;
		case 3:
			mvwprintw(stdscr, i, 0, "Coooool!\n");
			break;
		case 4:
			mvwprintw(stdscr, i, 0, "Cool!\n");
			break;
		case 5:
			mvwprintw(stdscr, i, 0, "Col!\n");
			break;
		case 6:
			mvwprintw(stdscr, i, 0, "Cl!\n");
			break;

	}
}

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

int Generate_word(char *word)
{
	srand(time(NULL));

	FILE* file = fopen("en_dict.txt", "r");
	if (file == NULL)
	{
		fprintf(stderr, "Can't open dict!");
		return 1;
	}
    fseek(file, 0L, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);

	int number_row = rand() % (file_size / (LEN_WORDS + 1)); 
	fseek(file, (LEN_WORDS + 1) * number_row, SEEK_SET);

	if (fgets(word, LEN_WORDS + 1, file) == NULL)
	{
		fprintf(stderr, "Can't get a line!");
		return 1;
	}

	fseek(file, 0L, SEEK_SET);
	fclose(file);
	return 0;
}

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

int main(int argc, char* argv[])
{
	if (argc == 2 && !(strcmp(argv[1], "-h") && strcmp(argv[1], "-help")))
	{
		printf("Usage: %s [OPTIONS]\n", argv[0]);
		printf("%s -h, --help - Help information\n", argv[0]);
		printf("LC_ALL=ru_RU.UTF-8 %s - play in russian\n", argv[0]);
	}
	
	if (Play())
	{
		return 1;
	}

	return 0;
}
