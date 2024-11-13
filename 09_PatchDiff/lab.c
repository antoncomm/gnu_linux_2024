#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum
{
	CLOSE=0x00,
	LEFT=0x01, 
	RIGHT=0x02, 
	UP=0x04, 
	DOWN=0x08
} direction;

void delete_walls(direction* lab, int* count_conn, int N)
{
	int r = 0;
	for(int i = 0; i < N * N; ++i)
	{
		if (i % N != N - 1 && !(lab[i] & DOWN)) // down
		{
			r = rand() % 2;
			if (r)
			{
				lab[i] |= DOWN; ++count_conn[i];
				lab[i+1] |= UP; ++count_conn[i+1];
			}
		}
		if (i + N < N * N && !(lab[i] & RIGHT)) // right
		{
			r = rand() % 2;
			if (r)
			{
				lab[i] |= RIGHT; ++count_conn[i];
				lab[i + N] |= LEFT; ++count_conn[i+N];
			}
		}
	}
	
}

int check_connect(direction* lab, int* count_conn, int N)
{
	for(int i = 0; i < N * N; ++i)
	{
		if (!((lab[i] & LEFT && i - N >=0 && count_conn[i - N] > 1) ||
			(lab[i] & RIGHT && i + N < N * N && count_conn[i + N] > 1) ||
			(lab[i] & UP && (i % N != 0) && count_conn[i + 1] > 1) ||
			(lab[i] & DOWN && (i % N != N - 1) && count_conn[i - 1] > 1)))
		{
			return 0;
		}
	}
	return 1;
}

void print_row(direction* lab, direction dir, int row, int N)
{
	printf("#");
	for(int i = 0; i < N; ++i)
	{
		if (dir & RIGHT || dir & LEFT)
		{
			printf(".");
		}
		
		if (lab[i * N + row] & dir)
		{
			printf(".");		
		}
		else
		{
			printf("#");
		}
		
		if (dir & DOWN || dir & UP)
		{
			printf("#");
		}
	}
	printf("\n");

}

void print_lab(direction* lab, int N)
{
	print_row(lab, UP, 0, N);
	for (int j = 0; j < N; ++j)
	{
		print_row(lab, RIGHT, j, N);
		print_row(lab, DOWN, j, N);
	}
}

int main(int argc, char* argv[])
{
	srand(time(NULL));

	int N = 6;
	direction* lab = (direction*)malloc(N * N * sizeof(direction));
	int* count_conn = (int*)malloc(N * N * sizeof(int));

	for(int i = 0; i < N * N; ++i)
	{
		lab[i] = CLOSE;
		count_conn[i] = 0;
	}
	
	do
	{
		delete_walls(lab, count_conn, N);
	}
	while (!check_connect(lab, count_conn, N));

	print_lab(lab, N);

	free(lab);
	free(count_conn);

	return 0;
}
