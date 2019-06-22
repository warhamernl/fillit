/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zeewier_auxiliary.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 18:42:26 by mlokhors       #+#    #+#                */
/*   Updated: 2019/06/09 18:17:29 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_tetri(struct s_tetrimino *tetrimino, uint64_t *grid)
{
	grid[(*tetrimino).cubes[4][0] / 4] ^= 1ull << (63 - ((*tetrimino).cubes[4][1] + (*tetrimino).cubes[4][0] % 4 * 16));
	grid[((*tetrimino).cubes[4][0] + (*tetrimino).cubes[0][0])/ 4] ^= 1ull << (63 - ((*tetrimino).cubes[4][1] + (*tetrimino).cubes[0][1] + (((*tetrimino).cubes[4][0] + (*tetrimino).cubes[0][0]) % 4 * 16)));
	grid[((*tetrimino).cubes[4][0] + (*tetrimino).cubes[1][0])/ 4] ^= 1ull << (63 - ((*tetrimino).cubes[4][1] + (*tetrimino).cubes[1][1] + (((*tetrimino).cubes[4][0] + (*tetrimino).cubes[1][0]) % 4 * 16)));
	grid[((*tetrimino).cubes[4][0] + (*tetrimino).cubes[2][0])/ 4] ^= 1ull << (63 - ((*tetrimino).cubes[4][1] + (*tetrimino).cubes[2][1] + (((*tetrimino).cubes[4][0] + (*tetrimino).cubes[2][0]) % 4 * 16)));
	(*tetrimino).placed = (short int)0;
}

void     place_tetri(struct s_tetrimino *tetrimino, uint64_t *grid)
{
	grid[(*tetrimino).cubes[4][0] / 4] |= 1ull << (63 - ((*tetrimino).cubes[4][1] + (*tetrimino).cubes[4][0] % 4 * 16));
	grid[((*tetrimino).cubes[4][0] + (*tetrimino).cubes[0][0])/ 4] |= 1ull << (63 - (((*tetrimino).cubes[4][1] + (*tetrimino).cubes[0][1] ) + (((*tetrimino).cubes[4][0] + (*tetrimino).cubes[0][0]) % 4 * 16)));
	grid[((*tetrimino).cubes[4][0] + (*tetrimino).cubes[1][0])/ 4] |= 1ull << (63 - (((*tetrimino).cubes[4][1] + (*tetrimino).cubes[1][1] ) + (((*tetrimino).cubes[4][0] + (*tetrimino).cubes[1][0]) % 4 * 16)));
	grid[((*tetrimino).cubes[4][0] + (*tetrimino).cubes[2][0])/ 4] |= 1ull << (63 - (((*tetrimino).cubes[4][1] + (*tetrimino).cubes[2][1] ) + (((*tetrimino).cubes[4][0] + (*tetrimino).cubes[2][0]) % 4 * 16)));
	(*tetrimino).placed = (short int)1;
}

void  cubes_offsetter(uint64_t tetrimino, short int cubes[5][2])
{
	int i;
	int count;
	int count2;
	int	nl;

	nl = 0;
	i = 0;
	count = 0;
	count2 = 0;
	while (i < 64)
	{
		if (tetrimino & (1ull << (63 - i)))
		{
			nl = 0;
			nl = ((i + 1)/ 16);
			cubes[count][count2] = nl;
			count2++;
			cubes[count][count2] = i - (nl * 16);
			count++; 
			count2 = 0;
		}
		i++;		
	}
	count = 0;
	count2 = 0;
	while (count < 3)
	{
		count2 = 0;
		while (count2 < 2)
		{
			cubes[count][count2] = cubes[count][count2] - cubes[3][count2];
			count2++;
		}
		count++;
	}
	cubes[4][0] = cubes[3][0];
	cubes[4][1] = cubes[3][1];
}

short int	first_unplaced(struct s_tetrimino *tetriminos, const short int const_i) // should a const variable have a specific name? double check pls - Kim
{
	short int	i;

	i = 0;
	while (i < 26)
	{
		if (tetriminos[i].binary_tetrimino == 0)
			return (27); // dit is de code dat alles klaar is
		if (tetriminos[i].placed == 0 && i != const_i)
			break;
		i++;
	}
	return (i);
}

short int	next_unplaced(struct s_tetrimino *tetriminos, short int i)
{
	while (i < 26)
	{
		i++;
		if (tetriminos[i].binary_tetrimino == 0 && first_unplaced(tetriminos, 666) == 27)
			return (27); // dit is de code dat alles klaar is
		if (tetriminos[i].placed == 0)
			break;
	}
	return (i);
}