/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 18:28:34 by mlokhors       #+#    #+#                */
/*   Updated: 2019/06/09 18:52:31 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	test_tetri(struct s_tetrimino *tetri)
{
	int	i;
	int i2;

	i2 = 0;
	while (tetri[i2].binary_tetrimino != (uint64_t)0)
	{
		i = -1;
		printf("tetrimino %d has value: %llu\n", i + 1, tetri[i2].binary_tetrimino);
		while (i++ < 63)
		{
			if (tetri[i2].binary_tetrimino & (uint64_t)1 << (63 - i))
				printf("1");
			else
				printf("0");
			if ((i + 1) % 16 == 0 && i != 0)
				printf("\n");
		}
		printf("   h  w\n0  %d  %d  <- offset block 1\n1  %d  %d  <- offset block 2\n2  %d  %d  <- offset block 3\n3  %d  %d  <- this is the position of block 4(the downmost, rightmost cube)\n4  %d  %d  <- this is a walker\n\n", tetri[i2].cubes[0][0], tetri[i2].cubes[0][1], tetri[i2].cubes[1][0], tetri[i2].cubes[1][1], tetri[i2].cubes[2][0], tetri[i2].cubes[2][1], tetri[i2].cubes[3][0], tetri[i2].cubes[3][1], tetri[i2].cubes[4][0], tetri[i2].cubes[4][1]);
		i2++;
	}
}

/*
while (gridi < 4)
		{
			gridd = 0;
			while (gridd < 63)
			{
				if (grid[gridi] & 1 << i)
					printf("1");
				else 
					printf("0");
				if ((i + 1) % 16 == 0)
					printf("\n");
				gridd++;	
			}
			gridi++;
		}
*/

int		main(int argc, char **argv)
{
	int i;
	int d;
	int	x;
	int gridi;
	int gridd;
	struct s_tetrimino tetriminos[27];
	uint64_t			grid[4];

	gridi = 0;
	gridd = 0;
	d = 0;
	i = 0;
	x = -1;
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
		test_tetri(tetriminos);
		zeewier(tetriminos, grid);
		gridi = 0;
		while (gridi < 4)
		{
			gridd = 0;
			while (gridd < 64)
			{
				if (grid[gridi] & 1ull << gridd)
					printf("1");
				else 
					printf("0");
				if ((gridd + 1) % 16 == 0 && gridd != 0)
					printf("\n");
				gridd++;	
			}
			gridi++;
			printf("\n");
		}
		


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
//	grid = zeewier(tetriminos); // dit was om de syntax van zeewier te testen - Kim
	return(0);
}
/*
struct s_tetrimino	tetriminos[26];

tetriminos[0].cubes[3][0] = 1;
of
(tetriminos[0]).cubes[3][0] = 1;
*/
