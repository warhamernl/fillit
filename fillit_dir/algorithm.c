/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zeewier.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/06 12:30:31 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/07/06 12:30:34 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			fits_entire_grid(uint64_t *grid,
	struct s_tetrimino *tetriminos, const short int const_i)
{
	short int	i;

	i = 0;
	if ((grid[tetriminos[const_i].cubes[4][0] / 4] & 1ull <<
		(63 - (tetriminos[const_i].cubes[4][1] +
		tetriminos[const_i].cubes[4][0] % 4 * 16))) != 0)
		return (0);
	while (i < 3)
	{
		if ((grid[(tetriminos[const_i].cubes[4][0] +
			tetriminos[const_i].cubes[i][0]) / 4] & 1ull << (63 -
			((tetriminos[const_i].cubes[4][1] + tetriminos[const_i].cubes[i][1])
			+ ((tetriminos[const_i].cubes[4][0] +
			tetriminos[const_i].cubes[i][0]) % 4 * 16)))) != 0)
			return (0);
		i++;
	}
	return (1);
}

static void			grid_setter(uint64_t *grid, short int size)
{
	short int h;
	short int w;

	h = 0;
	grid[0] = 9223372036854775807LL * 2ULL + 1ULL;
	grid[1] = 9223372036854775807LL * 2ULL + 1ULL;
	grid[2] = 9223372036854775807LL * 2ULL + 1ULL;
	grid[3] = 9223372036854775807LL * 2ULL + 1ULL;
	while (h < size)
	{
		w = 0;
		while (w < size)
		{
			grid[h / 4] &= ~(1ull << (63 - (w + h % 4 * 16)));
			w++;
		}
		h++;
	}
}

static int			recursor(struct s_tetrimino *tetriminos, short int i,
				uint64_t *grid, short int size)
{
	short int	w_initialized;

	if (i == 26)
		return (1);
	w_initialized = 0;
	tetriminos[i].cubes[4][0] = height_initializer(tetriminos, i, size);
	while (tetriminos[i].cubes[4][0] < size)
	{
		tetriminos[i].cubes[4][1] =
			width_initializer(tetriminos, i, size, &w_initialized);
		while (tetriminos[i].cubes[4][1] < size)
		{
			if (fits_entire_grid(grid, tetriminos, i))
			{
				place_tetri(&tetriminos[i], grid);
				if (recursor(tetriminos,
					next_unplaced(tetriminos, i), grid, size))
					return (1);
				remove_tetri(&tetriminos[i], grid);
			}
			tetriminos[i].cubes[4][1]++;
		}
		tetriminos[i].cubes[4][0]++;
	}
	return (0);
}

void				algorithm(struct s_tetrimino *tetriminos,
				uint64_t *grid, short int *size)
{
	*size = 0;
	while (tetriminos[*size].binary_tetrimino != 0)
		(*size)++;
	*size = (short int)ft_sqrt(*size * 4);
	grid_setter(grid, *size);
	while (*size <= 16)
	{
		if (recursor(tetriminos, 0, grid, *size))
			return ;
		(*size)++;
		grid_setter(grid, *size);
	}
}
