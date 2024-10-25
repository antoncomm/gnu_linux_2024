#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	enum Errors {ARG_ERROR = 1, OPEN_ERROR, GETC_ERROR, PUTC_ERROR, CLOSE_ERROR, REMOVE_ERROR};
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s infile outfile\n", argv[0]);
		exit(ARG_ERROR);
	}

	FILE * fr= fopen(argv[1], "r");
	if (fr == NULL)
	{
		fprintf(stderr, "Can't open input file!\n");
		exit(OPEN_ERROR);
	}

	FILE * fw= fopen(argv[2], "w");
	if (fw == NULL)
	{
		fprintf(stderr, "Can't open output file!\n");
		exit(OPEN_ERROR);
	}
	
	int ch = fgetc(fr);
	if (ferror(fr))
	{
		fprintf(stderr, "Failed at fgetc!\n");
		if (remove(argv[2]) != 0)
		{
			fprintf(stderr, "Failed delete output file!\n");
			exit(REMOVE_ERROR);
		}
		exit(GETC_ERROR);
	}
	while(ch != EOF)
    {
    	fputc(ch, fw);
		if (ferror(fw))
		{
			fprintf(stderr, "Failed at fputc!\n");
			if (remove(argv[2]) != 0)
			{
				fprintf(stderr, "Failed delete output file!\n");
			    exit(REMOVE_ERROR);
			}
			exit(PUTC_ERROR);
		}
		ch = fgetc(fr);
		if (ferror(fr))
		{
			fprintf(stderr, "Failed at fgetc!\n");
			if (remove(argv[2]) != 0)
			{
				fprintf(stderr, "Failed delete output file!\n");
			    exit(REMOVE_ERROR);
			}
			exit(GETC_ERROR);
		}
    }

	if (fclose(fw) == EOF)
	{
		fprintf(stderr, "Failed fclose for output file!\n");
		if (remove(argv[2]) != 0)
		{
			fprintf(stderr, "Failed delete output file!\n");
			exit(REMOVE_ERROR);
		}
		exit(CLOSE_ERROR);
	}


	if (fclose(fr) == EOF)
	{
		fprintf(stderr, "Failed fclose for intput file!\n");
		if (remove(argv[2]) != 0)
		{
			fprintf(stderr, "Failed delete output file!\n");
			exit(REMOVE_ERROR);
		}
		exit(CLOSE_ERROR);
	}
	
	if (remove(argv[1]) != 0)
	{
		fprintf(stderr, "Failed delete input file!\n");
		exit(REMOVE_ERROR);
	}

	return 0;
}
