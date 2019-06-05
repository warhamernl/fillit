#include "fillit.h"

int		main(int argc, char **argv)
{
	int i;
	int d;
	struct s_tetrimino tetriminos[27];

	d = 0;
	i = 0;
	if (argc == 2)
	{
		while (i < 27)
		{
			d = 0;
			tetriminos[i].binary_tetrimino = 0;
			while (d < 5)
			{
				tetriminos[i].cubes[d][0] = 0;
				tetriminos[i].cubes[d][1] = 0;
				d++;
			}
			i++;
		}
		i = 0;
		opening(argv[1], tetriminos);
		while (i < 26)
		{
			cubes_offsetter(tetriminos[i].binary_tetrimino, tetriminos[i].cubes);
			i++;
		}
		printf("1");
		


//		 opening(argv[1], tetrimino);
		/*while (i < 27)
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
		}*/
	}
	else 
		write(1, "Usage: Source File Missing", 26); // moet nog goeie omschrijving maken KIMMY YOU CAN DO THIS CauSE YOU HANDY WITH WORDS
	return(0);
}
/*
struct s_tetrimino	tetriminos[26];

tetriminos[0].cubes[3][0] = 1;
of
(tetriminos[0]).cubes[3][0] = 1;
*/
