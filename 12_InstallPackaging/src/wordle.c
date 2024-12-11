#include"wordle.h"
#include "config.h"

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
