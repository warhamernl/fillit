/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zeewier_auxiliary.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/06 12:30:16 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/07/06 12:30:19 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

short int	height_initializer(struct s_tetrimino *tetriminos,
	short int i, short int size)
{
	if (tetriminos[i].binary_tetrimino == tetriminos[i - 1].binary_tetrimino)
	{
		if (tetriminos[i - 1].cubes[4][1] + 1 < size)
			return (tetriminos[i - 1].cubes[4][0]);
		else
			return (tetriminos[i - 1].cubes[4][0] + 1);
	}
	else
		return (tetriminos[i].cubes[3][0]);
}

short int	width_initializer(struct s_tetrimino *tetriminos,
	short int i, short int size, short int *w_initialized)
{
	if (*w_initialized == 0 &&
		tetriminos[i].binary_tetrimino == tetriminos[i - 1].binary_tetrimino
		&& tetriminos[i - 1].cubes[4][1] + 1 < size)
	{
		*w_initialized = 1;
		return (tetriminos[i - 1].cubes[4][1] + 1);
	}
	else
		return (tetriminos[i].cubes[3][1]);
}

void		remove_tetri(struct s_tetrimino *tetrimino,
	unsigned long long *grid)
{
	grid[(*tetrimino).cubes[4][0] / 4] ^= 1ull << (63 -
		((*tetrimino).cubes[4][1] + (*tetrimino).cubes[4][0] % 4 * 16));
	grid[((*tetrimino).cubes[4][0] + (*tetrimino).cubes[0][0]) / 4] ^=
		1ull << (63 - ((*tetrimino).cubes[4][1] + (*tetrimino).cubes[0][1] +
			(((*tetrimino).cubes[4][0] + (*tetrimino).cubes[0][0]) % 4 * 16)));
	grid[((*tetrimino).cubes[4][0] + (*tetrimino).cubes[1][0]) / 4] ^=
		1ull << (63 - ((*tetrimino).cubes[4][1] + (*tetrimino).cubes[1][1] +
			(((*tetrimino).cubes[4][0] + (*tetrimino).cubes[1][0]) % 4 * 16)));
	grid[((*tetrimino).cubes[4][0] + (*tetrimino).cubes[2][0]) / 4] ^=
		1ull << (63 - ((*tetrimino).cubes[4][1] + (*tetrimino).cubes[2][1] +
			(((*tetrimino).cubes[4][0] + (*tetrimino).cubes[2][0]) % 4 * 16)));
	(*tetrimino).placed = 0;
}

void		place_tetri(struct s_tetrimino *tetrimino, unsigned long long *grid)
{
	grid[(*tetrimino).cubes[4][0] / 4] |= 1ull << (63 -
		((*tetrimino).cubes[4][1] + (*tetrimino).cubes[4][0] % 4 * 16));
	grid[((*tetrimino).cubes[4][0] + (*tetrimino).cubes[0][0]) / 4] |=
		1ull << (63 - (((*tetrimino).cubes[4][1] + (*tetrimino).cubes[0][1]) +
			(((*tetrimino).cubes[4][0] + (*tetrimino).cubes[0][0]) % 4 * 16)));
	grid[((*tetrimino).cubes[4][0] + (*tetrimino).cubes[1][0]) / 4] |=
		1ull << (63 - (((*tetrimino).cubes[4][1] + (*tetrimino).cubes[1][1]) +
			(((*tetrimino).cubes[4][0] + (*tetrimino).cubes[1][0]) % 4 * 16)));
	grid[((*tetrimino).cubes[4][0] + (*tetrimino).cubes[2][0]) / 4] |=
		1ull << (63 - (((*tetrimino).cubes[4][1] + (*tetrimino).cubes[2][1]) +
			(((*tetrimino).cubes[4][0] + (*tetrimino).cubes[2][0]) % 4 * 16)));
	(*tetrimino).placed = 1;
}

short int	next_unplaced(struct s_tetrimino *tetriminos, short int i)
{
	i++;
	while (i < 26)
	{
		if (tetriminos[i].binary_tetrimino != 0 && tetriminos[i].placed == 0)
			break ;
		i++;
	}
	return (i);
}
