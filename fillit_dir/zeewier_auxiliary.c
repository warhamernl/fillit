
#include "fillit.h"

void  cubes_offsetter(uint64_t tetrimino, int cubes[4][2])
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
}
