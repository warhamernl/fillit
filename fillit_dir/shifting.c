/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shifting.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 08:04:10 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/07/04 08:25:04 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			tetromove(
	int check, int *bracket, unsigned long long *tetro)
{
	int count;

	while (check != 1)
	{
		count = 0;
		while (count < 4)
		{
			bracket[count] += 1;
			count++;
		}
		*tetro <<= 1;
		count = 0;
		while (count < 4)
		{
			if (bracket[count] % 16 == 15)
			{
				check = 1;
				break ;
			}
			count++;
		}
	}
}

static int			checkit(int *bracket)
{
	int count;

	count = 0;
	while (count < 4)
	{
		if (bracket[count] % 16 == 15)
			return (1);
		count++;
	}
	return (0);
}

static void			movebracket(int *bracket, unsigned long long *tetro)
{
	while (bracket[3] + 16 < 64)
	{
		*tetro <<= 16;
		bracket[3] += 16;
		bracket[2] += 16;
		bracket[1] += 16;
		bracket[0] += 16;
	}
}

static void			inzero(unsigned long long tetro, int *bracket)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < 4)
	{
		bracket[i] = 0;
		i++;
	}
	while (count != 4)
	{
		if (tetro & (1ull << i))
		{
			bracket[count] = i;
			count++;
		}
		i++;
	}
}

unsigned long long	shift(unsigned long long tetro)
{
	int count;
	int bracket[4];
	int check;

	count = 0;
	check = 0;
	inzero(tetro, bracket);
	movebracket(bracket, &tetro);
	check = checkit(bracket);
	tetromove(check, bracket, &tetro);
	return (tetro);
}
