#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define MAXGR 10

void print_errors(int status, const regex_t* regex)
{
	int errbuf_size = 100;
	char* errbuf = NULL;
	if ((errbuf = (char*)malloc(errbuf_size * sizeof(char))) == NULL)
	{
		fprintf(stderr, "./esub: Can't allocate memory for error buffer\n");
		exit(1);
	}
	regerror(status, regex, errbuf, errbuf_size);
	printf("%s\n", errbuf);
	free(errbuf);
}

int main(int argc, char *argv[]) {
	if (argc != 4)
	{
		fprintf(stderr, "./esub Usage: ./esubc <regexp> <substitution> <string>\n");
		exit(1);
	}

	int status;
    regex_t regex;
	regmatch_t bags[MAXGR];

    if ((status = regcomp(&regex, argv[1], REG_EXTENDED)) != 0)
	{
		fprintf(stderr, "./esub: In regcomp():\n");
		print_errors(status, &regex);
		exit(1);
	}

	if ((status = regexec(&regex, argv[3], MAXGR, bags, REG_EXTENDED)) != 0)
	{
		fprintf(stderr, "./esub: In regexec():\n");
		print_errors(status, &regex);
		exit(1);				
	}

    // substitution
	// find all reference and write starts to bstart
	int len = strlen(argv[2]);
	for(int i = 0; i < len; ++i)
	{
		if(argv[2][i] == '\\' && i + 1 < len)
		{
			if (argv[2][i+1] == '\\')
			{
				++i;
			}
			else if('1' <= argv[2][i+1] && argv[2][i+1] <= '9')
			{
				if (bags[argv[2][i+1] - '0'].rm_eo - bags[argv[2][i+1] - '0'].rm_so == 0)
				{
					fprintf(stderr, "./esub: Invalid back reference\n");
					exit(1);
				}
				++i;
			}
		}
	}

	//print results
	for (int i = 0; i < bags[0].rm_so; ++i)
	{
		printf("%c", argv[3][i]);
	}

	for (int i = 0; i < len; ++i)
	{
		if(argv[2][i] == '\\' && i + 1 < len)
		{
			if (argv[2][i+1] == '\\')
			{
				printf("\\");
				++i;
			}
			else if ('1' <= argv[2][i+1] && argv[2][i+1] <= '9')
			{
				int index_ref = argv[2][i+1] - '0';
				for (int j = bags[index_ref].rm_so; j < bags[index_ref].rm_eo; ++j)
				{
					printf("%c", argv[3][j]);
				}
				++i;
			}
			else
			{
				printf("\\");
			}
		}
		else
		{
			printf("%c", argv[2][i]);
		}
	}
	
	int len_str = strlen(argv[3]);
	for (int i = bags[0].rm_eo; i < len_str; ++i)
	{
		printf("%c", argv[3][i]);
	}
	printf("\n");

	regfree(&regex);
    return 0;
}
