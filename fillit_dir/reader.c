/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <mlokhors@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 18:41:59 by mlokhors       #+#    #+#                */
/*   Updated: 2019/07/07 13:40:01 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static uint64_t		convert(char *str)
{
	int			i;
	uint64_t	tetro;
	int			nl;

	nl = 0;
	tetro = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (i == 4 || i == 9 ||
			i == 14 || i == 19 || i == 20))
			nl++;
		if (str[i] == '#')
			tetro |= (1ull << ((63 - i + nl) - (nl * 12)));
		i++;
	}
	if ((nl != 5 && i == 21) || (nl != 4 && i == 20))
	{
		write(1, "error\n", 6);
		exit(-1);
	}
	return (shift(tetro));
}

static int			border(char *str, int i)
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

static int			check(char *str)
{
	int	i;
	int squarecount;
	int neighbour;

	neighbour = 0;
	squarecount = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (-1);
		if (str[i] == '#')
		{
			neighbour += border(str, i);
			squarecount++;
			if (squarecount > 4)
				return (-1);
		}
		i++;
	}
	if (neighbour != 6 && neighbour != 8)
		return (-1);
	return (neighbour);
}

static uint64_t		lezen(int fd, int *bytes_read)
{
	uint64_t	tetro;
	char		*cache;
	int			checki;

	tetro = 0;
	cache = ft_strnew(21);
	*bytes_read += read(fd, cache, 21);
	if (cache[0] == '\0')
	{
		free(cache);
		return (0);
	}
	checki = check(cache);
	if (checki == -1)
	{
		write(1, "error\n", 6);
		exit(-1);
	}
	tetro = convert(cache);
	free(cache);
	return (tetro);
}

int					opening(char *str, struct s_tetrimino tetriminos[27])
{
	int			fd;
	int			i;
	int			bytes_read;

	bytes_read = 0;
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (tetriminos[i].binary_tetrimino == 0)
	{
		tetriminos[i].binary_tetrimino = lezen(fd, &bytes_read);
		if (i == 26)
			return (-1);
		if (tetriminos[i].binary_tetrimino == 0)
			break ;
		i++;
	}
	close(fd);
	total_read(i, bytes_read);
	return (0);
}
