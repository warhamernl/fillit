/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 18:28:34 by mlokhors       #+#    #+#                */
/*   Updated: 2019/07/04 08:38:19 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		identify_tetri(struct s_tetrimino *tetriminos,
					short int h, short int w)
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

static void		print_output(unsigned long long *grid,
					struct s_tetrimino *tetriminos, short int *size)
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

static void		empty(struct s_tetrimino *tetriminos)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (i < 27)
	{
		x = 0;
		tetriminos[i].binary_tetrimino = 0;
		tetriminos[i].placed = 0;
		while (x < 5)
		{
			tetriminos[i].cubes[x][0] = 0;
			tetriminos[i].cubes[x][1] = 0;
			x++;
		}
		i++;
	}
}

static void		whileoffsetter(struct s_tetrimino *tetriminos)
{
	int i;

	i = 0;
	while (i < 26)
	{
		cubes_offsetter(tetriminos[i].binary_tetrimino,
			tetriminos[i].cubes);
		i++;
	}
}

int				main(int argc, char **argv)
{
	struct s_tetrimino		tetriminos[27];
	unsigned long long		grid[4];
	short int				size;

	if (argc == 2)
	{
		empty(tetriminos);
		if (opening(argv[1], tetriminos) == -1)
		{
			write(1, "error\n", 6);
			return (-1);
		}
		whileoffsetter(tetriminos);
		algorithm(tetriminos, grid, &size);
		print_output(grid, tetriminos, &size);
	}
	else
		write(1, "Usage: Source File Missing\n", 27);
	return (0);
}
