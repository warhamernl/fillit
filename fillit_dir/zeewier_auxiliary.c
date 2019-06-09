/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zeewier_auxiliary.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 18:42:26 by mlokhors       #+#    #+#                */
/*   Updated: 2019/06/09 11:43:34 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void     place_tetri(struct s_tetrimino *tetrimino, uint64_t *grid)
{
	int x; // kun je x & y veranderen naar h & w in het belang van uniformiteit en expliciteit?
	int y;

	x = (*tetrimino).cubes[4][0] / 4;
	y = (*tetrimino).cubes[4][1] / 4;
	grid[(*tetrimino).cubes[4][0] / 4] |= 1 << (63 - (x + y * 16));
	grid[(*tetrimino).cubes[4][0] / 4] |= 1 << (63 - ((x + (*tetrimino).cubes[0][1]) + (y * 16 + (*tetrimino).cubes[0][0])));
	grid[(*tetrimino).cubes[4][0] / 4] |= 1 << (63 - ((x + (*tetrimino).cubes[1][1]) + (y * 16 + (*tetrimino).cubes[1][0])));
	grid[(*tetrimino).cubes[4][0] / 4] |= 1 << (63 - ((x + (*tetrimino).cubes[2][1]) + (y * 16 + (*tetrimino).cubes[2][0])));

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
