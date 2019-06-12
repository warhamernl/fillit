/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zeewier.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 18:01:36 by kde-wint       #+#    #+#                */
/*   Updated: 2019/06/09 19:04:40 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int      fits_entire_grid(uint64_t *grid, short int cubes[5][2])
{
    short int   i;
    
    i = 0;
    while (i < 3)
    {
        if (cubes[4][0] % 4 + cubes[i][0] < 0)
            if ((grid[(cubes[4][0] + cubes[i][0]) % 4] &
                1 << (63 - ((cubes[4][1] + cubes[i][1]) + (cubes[4][0] + (cubes[i][0] % 4 * 16))))) != 0)
                return (0);
        i++;
    }
    return(1);
}

static void     grid_setter(uint64_t *grid, short int *size)
{
    short int h;
    short int w;

    h = 0;
    grid[0] = 9223372036854775807LL * 2ULL + 1ULL;
    grid[1] = 9223372036854775807LL * 2ULL + 1ULL;
    grid[2] = 9223372036854775807LL * 2ULL + 1ULL;
    grid[3] = 9223372036854775807LL * 2ULL + 1ULL;
    while (h < *size)
    {
        w = 0;
        while (w < *size) // tip: deze kan ik misschien in chunks doen bij grotere speelvelden
        {
            grid[h / 4] &= ~(1ull << (63 - (w + h % 4 * 16)));
            w++;
        }
        h++;
    }

}

static int      can_fit(struct s_tetrimino *tetrimino, uint64_t *grid, short int *size)
{
    (*tetrimino).cubes[4][0] = (*tetrimino).cubes[3][0];
    while ((*tetrimino).cubes[4][0] < *size)
    {
        (*tetrimino).cubes[4][1] = (*tetrimino).cubes[3][1];
        while ((*tetrimino).cubes[4][1] < *size)
        {
            if ((grid[(*tetrimino).cubes[4][0] / 4] & (*tetrimino).binary_tetrimino >> (((*tetrimino).cubes[4][1] - (*tetrimino).cubes[3][1]) + ((*tetrimino).cubes[4][0] + (*tetrimino).cubes[3][0]) % 4 * 16)) == 0 &&
                    fits_entire_grid(grid, (*tetrimino).cubes) == 1)
            {
                place_tetri(tetrimino, grid);
                return (1);
            }
            (*tetrimino).cubes[4][1]++;
        }
        (*tetrimino).cubes[4][0]++;
    }
    return (0);
}

static char  recursor(struct s_tetrimino *tetriminos, short int i, uint64_t *grid, short int *size)
{
    if (tetriminos[i].binary_tetrimino == 0)
        return (1);
    if (can_fit(&tetriminos[i], grid, size))
    {
        if (recursor(tetriminos, i + 1, grid, size))
            return (1);
        else
        {
            remove_tetri(tetriminos, i, grid);
            return (0);
        }
    }
    return (0);
}

void        zeewier(struct s_tetrimino *tetriminos, uint64_t *grid, short int *size)
{
    *size = 0;
    while (tetriminos[*size].binary_tetrimino != 0)
        (*size)++;
    *size = (short int)ft_sqrt(*size * 4);
    grid_setter(grid, size);
    while (recursor(tetriminos, 0, grid, size) == 0 && *size < 26)
    {
        (*size)++;
        grid_setter(grid, size);
    }
}

/*
Aantekeningen van praatje met Emily:
     0100 == (1 << 2)
     1011 == ~(1 << 2)
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