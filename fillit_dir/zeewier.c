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
    int         h;
    int         w;

    h = 0;
    while (h < size)
    {
        w = 0;
        while (w < size)
        {
            if (grid[h / 4] & tetrimino >> w + h % 4 * 16 == 0)
                return (1);
            w++;
        }
        h++;
    }
    return (0);
}

uint64_t        *zeewier(uint64_t tetrimino, size_t size) // size bij eerste call: wortel van (tetriminos * 4) //(decimalen?)
{
    uint64_t    grid[4];

    grid_setter(size, &grid);
    can_fit(tetrimino, size, &grid);
/*    if (can_fit(grid, size, tetrimino[i]))
    {

    }*/
    return (zeewier(tetrimino, size + 1));
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
