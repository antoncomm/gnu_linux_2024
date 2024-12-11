#include"wordle.h"

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
