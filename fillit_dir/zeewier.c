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

static void     grid_setter(t_uint256 *grid, size_t size)
{
    int h;
    int w;

    h = 0;
    grid->value[0] = 18446744073709551615;
    grid->value[1] = 18446744073709551615;
    grid->value[2] = 18446744073709551615;
    grid->value[3] = 18446744073709551615;
    while (h < size)
    {
        w = 0;
        while (w < size) // deze kan ik waarschijnlijk in chunks doen bij grotere speelvelden
        {
            *grid->value = ~(1 << 255 - (w + ( h * 16)));
            w++;
        }
    }
}

int             can_fit(t_uint256 *grid, size_t size, t_uint256 tetrimino)
{
    t_uint256           testgrid;
    int                 h;
    int                 w;

    h = 0;
    while (h < size)
    {
        w = 0;
        while (w < size)
        {
            testgrid = *grid->value & (*tetrimino.value >> h * 16 + w);
            // ifje
            w++;
        }
        h++;
    }
    return (0);
}

uint64_t        *zeewier(t_uint256 *tetrimino, size_t size) // size bij eerste call: wortel van (tetriminos * 4) //(decimalen?)
{
    t_uint256   grid;

    grid_setter(&grid, size);
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
