/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 18:41:59 by mlokhors       #+#    #+#                */
/*   Updated: 2019/06/09 15:43:51 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


static void	tetromove(int check, int *bracket, uint64_t *tetro)
{
	int count;

	count = 0;
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
				break;
			}
			count++;
		}		
	}
}

static 	int	checkit(int *bracket)
{
	int count;

	count = 0;
	while (count < 4)
	{
		if (bracket[count] % 16 == 15)
			return(1);
		count++;
	}
	return (0);
}

static	void movebracket(int *bracket, uint64_t *tetro)
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

static	void inzero(uint64_t tetro, int *bracket)
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

static uint64_t shift(uint64_t tetro)
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
	return(tetro);
}

static uint64_t	convert(char *str)
{
	int i;
	uint64_t tetro;
	int nl;

	nl = 0;
	tetro = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (i == 4 || i == 9 || i == 14 || i == 19 || i == 20))
			nl++;
		if (str[i] == '#')
		{
			tetro |= (1ull << ((63 - i + nl) - (nl * 12))); 
		}
		i++;
	}
	if (nl != 5 && i == 21)
	{
		printf("error in convert");
		exit(-1);
	}
	return (shift(tetro));
}

static int		border (char *str , int i)
{
	int side;

	side = 0;
	if (str[i] == '#' && i + 5 < 21 && str[i + 5] == '#')
		side++;
	if (str[i] == '#' && i - 5 >= 0 && str[i - 5] == '#')
		side++;
	if (str[i] == '#' && i + 1 < 21 && str[i + 1] == '#')
		side++;
	if (str[i] == '#' && i - 1 >= 0 && str[i - 1] == '#')
		side++;
	return (side);
}

static int		check(char *str)
{
	int i;
	int squarecount;
	int neighbour;

	neighbour = 0;
	squarecount = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return(-1);
		if (str[i] == '#')
		{
			neighbour += border(str, i);
			squarecount++;
			if (squarecount > 4)
				return(-1);
		}
		i++;
	}
	if (neighbour != 6 && neighbour != 8)
		return (-1);
	return(neighbour);
}


static uint64_t		lezen(int fd)
{
	uint64_t	tetro;
	char 		*cache;
	int			checki;

	tetro = 0;
	cache = ft_strnew(21);
	read(fd, cache, 21);
	if (cache[0] == '\0')
		return (0);
	checki = check(cache);
	if (checki == -1)
	{
		printf("error in lezen");// geen printf pls
		exit(-1);
	}
	tetro = convert(cache);
	free(cache);
	return (tetro);
}

void	opening(char *str, struct s_tetrimino tetriminos[27])
{
	int			fd;
	int			i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error opining", 6);
		exit(-1);
	}
	while (tetriminos[i].binary_tetrimino == 0)
	{
		tetriminos[i].binary_tetrimino = lezen(fd);
		if (i == 26)
		{
			printf("Error 26 tetro bereikt"); // geen printf pls
			exit(-1);
		}
		if (tetriminos[i].binary_tetrimino == 0)
			break;
		i++;	
	}
	close(fd);
}
