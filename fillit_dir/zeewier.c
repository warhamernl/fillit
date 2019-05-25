#include "fillit.h"

static void         grid_setter(unsigned short **grid, size_t size)
{
    int     i;

    i = 0;
    size *= size;
    while (size >= 16)
    {
        *grid[i] = 0;
        size -= 16;
        i++;
    }
    if (size > 0)
    {
        *grid[i] = 65535;
        while (size > 0)
        {
            *grid[i] = ~(1 << 15 - size);
            size--;
        }
        i++;
    }
    while (i < 16)
    {
        *grid[i] = 65535;
        i++;
    }
}

int                 can_fit(unsigned short *grid, size_t size, unsigned short tetrimino)
{
    unsigned short  orig[16];
    int                 i;

    orig = grid;
    i = 0;
    *grid = *grid & tetrimino;
    while (i < size)
    {
        if (*(grid + i) & (1<<(255 - i))) // dit checkt of de nieuw-geplaatste tetrimino in conflict is met een al gezette tetrimino
        {

        }
        i++;
    }
    return (0);
}

unsigned short  *zeewier(unsigned short *tetrimino, size_t size, int i) // size is number of tetriminos
{
    unsigned short  grid[16];

    grid_setter(grid, size);
/*    if (can_fit(grid, size, tetrimino[i]))
    {

    }*/
    return (grid);
}

/*
     0100 = (1 << 2)
     1011 = ~(1 << 2)
eerst kijken of A past
zoniet, increment size
dan plaats je A,
probeer A en dan B te passen,
lukt dat niet, probeer C(t/m Z),
lukt niks daarvan, probeer B als eerste en daarna A,

short arr[16];

long* x = (long*)&arr[2];

aabb............
.abb............
.a.............. | 16 
................ | 16 \ 64 
................ | 16 /
................ | 16
................
................
................
................
................
................
................
................
................
................
*/