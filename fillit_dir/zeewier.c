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

/*
MARK:
Als je tijd over hebt, heb ik de volgende dingen nog nodig...
    - functie beschreven in de "PLACEHOLDER" in can_fit
    - functie beschreven in de "PLACEHOLDER" in recursor
    - een within_bounds functie, maar die schrijf ik denk ik liever zelf
*/

static int      fits_entire_grid(uint64_t *grid, char **cubes) // Unfinished.
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

static void     grid_setter(short int size, uint64_t *grid)
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
        while (w < size) // tip: deze kan ik misschien in chunks doen bij grotere speelvelden
        {
            grid[h / 4] = ~(1 << 63 - (w + h % 4 * 16));
            w++;
        }
    }
}

static int      can_fit(struct s_tetrimino *tetrimino, uint64_t *grid, short int size)
{
    (*tetrimino).cubes[4][0] = (*tetrimino).cubes[3][0];
    while ((*tetrimino).cubes[4][0] < size)
    {
        (*tetrimino).cubes[4][1] = (*tetrimino).cubes[3][1];
        while ((*tetrimino).cubes[4][1] < size)
        {
            if (grid[(*tetrimino).cubes[4][0] / 4] & (*tetrimino).binary_tetrimino >>
                ((*tetrimino).cubes[4][1] - (*tetrimino).cubes[3][1]) + ((*tetrimino).cubes[4][0] - (*tetrimino).cubes[3][0]) % 4 * 16 == 0 &&
                    within_bounds(grid, (*tetrimino).cubes) &&
                        fits_entire_grid(grid, (*tetrimino).cubes))
            {
                // PLACEHOLDER: function call that actually places the tetrimino in the grid
                return (1);
            }
            (*tetrimino).cubes[4][1]++;
        }
        (*tetrimino).cubes[4][0]++;
    }
    return (0);
}

static char  recursor(struct s_tetrimino **tetriminos, short int i, uint64_t *grid, short int size)
{
    if (tetriminos[i] == NULL)
        return (1);
    if (can_fit(tetriminos[i], grid, size))
    {
        if (recursor(tetriminos, i + 1, grid, size))
            return (1);
        else
        {
            // PLACEHOLDER: function call to remove the tetri this function placed if the recursion-branch doesn't work out
            return (0);
        }
    }
        return (0);
}

uint64_t        *zeewier(struct s_tetrimino **tetriminos)
{
    uint64_t    grid[4];
    short int   size;

    size = 0;
    while (tetriminos[size] != NULL)
        size++;
    size = ft_root(size * 4);
    grid_setter(size, grid);
    while (recursor(tetriminos, 0, grid, size) == 0 && size < 26)
        size++;
    return (grid); // zijn er gevallen waar iets anders gereturned moet worden? invalid input/impossible solutions?
}

/*
Aantekeningen van praatje met Emily:
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
