/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_auxiliary.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 18:28:34 by mlokhors       #+#    #+#                */
/*   Updated: 2019/07/04 08:38:19 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		cubes_follow(short int cubes[5][2])
{
	int count;
	int count2;

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

void			cubes_offsetter(unsigned long long tetrimino,
	short int cubes[5][2])
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
			nl = ((i + 1) / 16);
			cubes[count][count2] = nl;
			count2++;
			cubes[count][count2] = i - (nl * 16);
			count++;
			count2 = 0;
		}
		i++;
	}
	cubes_follow(cubes);
}
