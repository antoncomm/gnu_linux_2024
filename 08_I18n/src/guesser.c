#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#include "config.h"

#define _(STRING) gettext(STRING)

int main(int argc, char *argv[])
{
	int beg = 50, end = 100;
	char *answer = NULL;
	size_t len = 0;
	int tmp = 0;
	
	setlocale (LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALEDIR);
	textdomain(PACKAGE);

	printf(_("Think of a number from 1 to 100.\n"));
	
	while(beg < end)
	{
		printf(_("Is your number bigger than %d?\n"), beg);
		if (getline(&answer, &len, stdin))
		{
			answer[strlen(answer) - 1] = '\0';
			if (strcmp(_(answer), _("yes")) == 0)
			{
				beg += (end - beg + 1) / 2;
			}
			else if (strcmp(_(answer), _("no")) == 0)
			{
				tmp = beg;
				beg -= (end - beg + 1) / 2;
				end = tmp;
			}
			else
			{
				printf(_("Don't undersand you!\n"));
			}
		}
		else
		{
			printf(_("Don't undersand you!\n"));
		}
	}
	
	printf(_("Your number is %d!\n"), beg);
	
	free(answer);
	return 0;
}
