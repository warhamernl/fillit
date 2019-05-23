#include "fillit.h"

void print_binary(unsigned short int number) // remove before turning in
{
    if (number) {
        print_binary(number >> 1);
        putc((number & 1) ? '1' : '0', stdout);
    }
}

int		main(int argc, char **argv)
{
	unsigned short int	tetrimino[27] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // laten we een manier vinden om dit 26 te maken
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
			print_binary(tetrimino[i]);
            write(1, "\n", 1);
			i++;
		}
	}
	else 
		write(1, "Error", 6);
	return(0);
}
