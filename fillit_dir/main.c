#include "fillit.h"

int		main(int argc, char **argv)
{
	uint64_t	tetrimino[27]; // laten we een manier vinden om dit 26 te maken
	int i;

	i = 0;
	while (i < 27)
	{
		tetrimino[i] = 0;
		i++;
	}
	i = 0;
	if (argc == 2)
	{
//		 opening(argv[1], tetrimino);
		while (i < 27)
		{
			opening(argv[1], tetrimino);
			printf("%llu\n", tetrimino[i]);
			i++;
		}
	}
	else 
		write(1, "Error", 6);
	return(0);
}
