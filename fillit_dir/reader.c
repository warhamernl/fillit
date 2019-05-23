#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

short int	convert(char *str)
{
	int i;
	unsigned short int tetro;
	int nl;
	
	nl = 0;
	tetro = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nl++;
		if (str[i] == '#')
		{
			
			tetro |= (1 << (15 - i + nl)); 
		}
		i++;
	}
	return (tetro);
}


int		border (char *str , int i)
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

int		check(char *str)
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
		{
			printf("error 1 in check");
			exit(-1);
		}
		if (str[i] == '#')
		{
			squarecount++;
			if (squarecount > 4)
			{
				printf("error 2 in check");
				exit(-1);
			}
		}
		i++;
	}
	i = 0;
	while (str[i] != '#' && str[i] != '\0')
		i++;
	while (i < 21)
	{
		neighbour += border(str, i);
		i++;
	}
	if (neighbour != 6 && neighbour != 8)
		return (-1);
	return(neighbour);
}


unsigned short int		lezen(int fd)
{
	unsigned short int	tetro;
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
		printf("error in lezen");
		exit(-1);
	}
	tetro = convert(cache);
	free(cache);
	return (tetro);
}

 void opening(char *str, unsigned short int *tetrimino)
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
	while (tetrimino[i] != 0)
	{
		tetrimino[i] = lezen(fd);
		if (i == 26)
		{
			printf("Error 26 tetro bereikt");
			exit(-1);
		}
		if (tetrimino[i] == 0)
			break;
		i++;	
	}
	close(fd);
//	return(tetrimino);
}

int		main(int argc, char **argv)
{
	unsigned short int tetrimino[27] = {1};
	int i;

	i = 0;
	if (argc == 2)
	{
		while (i < 27)
		{
			opening(argv[1], tetrimino);
			printf("%hu", tetrimino[i]);
			i++;
		}
	}
	else 
		write(1, "Error", 6);
	return(0);
}
