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

int             can_fit(uint64_t tetrimino, size_t size, uint64_t *grid)
{
    int         cubes[4][2]; // this stores the height and width of the last cube of the tetrimino, and the offset of preceeding elements

    cubes_offsetter(tetrimino, &cubes);
    while (cubes[3][0] < size)
    {
        cubes[3][1] = 0;
        while (cubes[3][0] < size)
        {
            if (grid[cubes[3][0] / 4] & tetrimino >> cubes[3][1] + cubes[3][0] % 4 * 16 == 0 &&
                    within_bounds(&grid, &cubes) &&
                        fits_entire_grid(&grid, &cubes))
            {
                // function/something that actually places the tetrimino in the grid
                return (1);
            }
            cubes[3][1]++;
        }
        cubes[3][0]++;
    }
    return (0);
}

uint64_t        *zeewier(uint64_t *old_grid, uint64_t *tetrimino, int i, size_t size) // size bij eerste call: wortel van (tetriminos * 4) //(decimalen?)
{
    uint64_t    new_grid[4];

//    if (old_grid == NULL)
//        grid_setter(size, &old_grid);
    grid_setter(size, &new_grid);
    can_fit(tetrimino, size, &new_grid);
    return (zeewier(new_grid, tetrimino, i, size + 1));
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
