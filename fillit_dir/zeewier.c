/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zeewier.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 18:01:36 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/05/27 18:01:40 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// static int   within_bounds(uint64_t *grid, uint64_t tetrimino, int **cubes)
// this function will check whether the tetrimino would be out-of-bounds, going across the border between two uint64_ts is fine though

// static void  cubes_offsetter(uint64_t tetrimino, int **cubes)
// this function will input the coordinate of the down-most, right-most cube in cubes[0], and will create off-sets for the other parts of the cube accordingly

static int      fits_entire_grid(uint64_t *grid, char **cubes)
{
    char    i;

    i = 0;
    while (i < 3)
    {
        (cubes[3][0] % 4 + cubes[i][0]) * 16 + 
        if (cubes[3][0] % 4 + cubes[i][0] < 0)
        {

        }
        i++;
    }
    return(-1);
}

static void     grid_setter(size_t size, uint64_t *grid)
{
    int h;
    int w;

    h = 0;
    grid[0] = 18446744073709551615;
    grid[1] = 18446744073709551615;
    grid[2] = 18446744073709551615;
    grid[3] = 18446744073709551615;
    while (h < size)
    {
        w = 0;
        while (w < size) // tip: deze kan ik waarschijnlijk in chunks doen bij grotere speelvelden
        {
            grid[h / 4] = ~(1 << 63 - (w + h % 4 * 16));
            w++;
        }
    }
}

static int      can_fit(uint64_t tetrimino, char size, uint64_t *grid)
{
    char        cubes[4][2]; // this stores the height and width of the last cube of the tetrimino, and the offset of preceeding elements
    char        walker[2];

    walker[0] = cubes[3][0];
    walker[1] = cubes[3][1];
    cubes_offsetter(tetrimino, cubes);
    while (walker[0] < size)
    {
        walker[1] = cubes[3][1];
        while (walker[1] < size)
        {
            if (grid[walker[0] / 4] & tetrimino >> (walker[1] - cubes[3][1]) + (walker[0] - cubes[3][0]) % 4 * 16 == 0 && within_bounds(&grid, &cubes) && fits_entire_grid(&grid, &cubes))
            {
                // function that actually places the tetrimino in the grid
                return (1);
            }
            walker[1]++;
        }
        walker[0]++;
    }
    return (0);
}

static char  recursor(uint64_t *tetrimino, char i, uint64_t *grid, char size)
{
    if (i == 26) // any chance I can shove this into a different part of this function? i don't like this check being run constantly
        return (1);
    if (can_fit(tetrimino[i], size, grid))
    {
        if (recursor(tetrimino, i + 1, grid, size)) // here it tries to place the next tetri
            return (1);
        else
        {
            // PLACEHOLDER remove the tetri this function placed if the recursion-branch doesn't work out
            return (0);
        }
    }
        return (0);
}

uint64_t        *zeewier(uint64_t *tetrimino) // size bij eerste call: wortel van (tetriminos * 4) //(decimalen?)
{
    uint64_t    grid[4];
    char        size;

    size = 0;
    while (tetrimino[size] != NULL)
        size++;
    size = ft_root(size * 4); // of moet dit zijn: size = (size * 4) / 2
    grid_setter(size, &grid);
    while (recursor(tetrimino, 0, grid, size) == 0 && size < 26)
        size++;
    return (&grid); // zijn er gevallen waar iets anders gereturned moet worden? invalid input/impossible solutions?
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
