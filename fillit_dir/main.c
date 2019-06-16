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

static char identify_tetri(struct s_tetrimino *tetriminos, short int h, short int w)
{
	short int	i;

	i = 0;
	while (tetriminos[i].binary_tetrimino != 0)
	{
		if (h == tetriminos[i].cubes[4][0] + tetriminos[i].cubes[0][0] &&
			w == tetriminos[i].cubes[4][1] + tetriminos[i].cubes[0][1])
			return (i + 'A');
		if (h == tetriminos[i].cubes[4][0] + tetriminos[i].cubes[1][0] &&
			w == tetriminos[i].cubes[4][1] + tetriminos[i].cubes[1][1])
			return (i + 'A');
		if (h == tetriminos[i].cubes[4][0] + tetriminos[i].cubes[2][0] &&
			w == tetriminos[i].cubes[4][1] + tetriminos[i].cubes[2][1])
			return (i + 'A');
		if (h == tetriminos[i].cubes[4][0] && w == tetriminos[i].cubes[4][1])
			return (i + 'A');
		i++;
	}
	return ('.');
}

void	print_output(uint64_t *grid, struct s_tetrimino *tetriminos, short int *size) // maak dit static voor submission
{
	short int	h;
	short int	w;

	h = 0;
	while (h < *size)
	{
		w = 0;
		while (w < *size)
		{
			if (grid[h / 4] & 1ull << (63 - (w + h % 4 * 16)))
				ft_putchar(identify_tetri(tetriminos, h, w));
			else
				ft_putchar('.');
			w++;
		}
		ft_putchar('\n');
		h++;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int d;
	int	x;
	int gridi;
	int gridd;
	struct s_tetrimino tetriminos[27];
	uint64_t			grid[4];
	short int	size;

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
		zeewier(tetriminos, grid, &size);
		gridi = 0;
		print_output(grid, tetriminos, &size);
	}
	else 
		write(1, "Usage: Source File Missing", 26);
	return(0);
}