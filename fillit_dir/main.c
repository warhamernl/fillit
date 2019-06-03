#include "fillit.h"

int		main(int argc, char **argv)
{
	uint64_t	tetrimino[27]; // laten we een manier vinden om dit 26 te maken
	int i;
	int cubes[4][2];
	int d;

	d = 0;
	i = 0;
	while (i < 27)
	{
		tetrimino[i] = 0;
		i++;
	}
	i = 0;
	if (argc == 2)
	{
//		 opening(argv[1], tetrimino);
		while (i < 27)
		{
			opening(argv[1], tetrimino);
			printf("%llu\n", tetrimino[i]);
			i++;
		}
		cubes_offsetter(tetrimino[0], cubes);
		while (d < 4)
		{
			printf("height %d, weight %d", cubes[d][0], cubes[d][1]);
			d++;
		}
	}
	else 
		write(1, "Error", 6);
	return(0);
}
