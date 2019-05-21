#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		convert(int fd, char *line)
{
	int			count;
	int			countsquare;
	short int	tetro;
	int 		ret;

	countsquare = 0;
	count = 0;	
	while ((read(fd, &line, 1) && count < 16))
	{
		if (*line != '.' && *line != '#' && *line != '\n')
			return(-1);
		if (*line == '.' || *line == '#')
		{
			if (*line == '#')
			{
				tetro = 1 << count;
				countsquare++;
			}
			if (countsquare > 4)
				return (-1);			
			count++;
		}
	}
	return (tetro);
}

int		opening(char *str)
{
	char		*line;
	int			fd;
	short int	tetromino[27];
	int			i;
	
	i = 0;
	;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error", 6);
		return (-1);
	}
	if (!line)
		ft_strnew(1);
	while ()
	{
		tetromino[i] = reader(fd, line);
		i++;
		if (i == 26)
			return(-1);
		if
	}


}
