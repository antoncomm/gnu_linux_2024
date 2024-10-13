#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	if (argc == 1)
    {
    	printf("Help\n");
		printf("You can сall the program with one argument N to get range [0, 1, ..., N-1];\n");
		printf("You can сall the program with two arguments M and N to get range [M, M+1, ..., N-1];\n");
		printf("You can сall the program with three arguments M, N and S to get range [M, M+S, M+2*S, ..., N-1].\n");
		return 0;
    }

	int M = 0, N = 0, S = 1;

	if (argc == 2)
	{
		N = atoi(argv[1]);
	}
	else if (argc == 3)
	{
		M = atoi(argv[1]); 
		N = atoi(argv[2]);
	}
	else if (argc == 4)
	{
		M = atoi(argv[1]);
		N = atoi(argv[2]);
		S = atoi(argv[3]);
	}
	else
	{
		fprintf(stderr, "There are too many arguments!\n");
		return 1;
	}
	
	int curr = M;
	for(; curr < N; curr+=S)
	{
		printf("%d\n", curr);
	}

	return 0;
}
