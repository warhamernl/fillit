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

static int      fits_entire_grid(uint64_t *grid, short int cubes[6][2])
{
    short int   i;
    
    i = 0;
    while (i < 3)
    {
        if (cubes[4][0] % 4 + cubes[i][0] < 0)
            if ((grid[(cubes[4][0] + cubes[i][0]) / 4] &
                1ull << (63 - ((cubes[4][1] + cubes[i][1]) + ((cubes[4][0] + cubes[i][0]) % 4 * 16)))) != 0)
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
        while (w < *size)
        {
            grid[h / 4] &= ~(1ull << (63 - (w + h % 4 * 16)));
            w++;
        }
        h++;
    }
}

static int      can_fit(struct s_tetrimino *tetrimino, uint64_t *grid, short int *size)
{
    (*tetrimino).cubes[4][0] = (*tetrimino).cubes[3][0] + (*tetrimino).cubes[5][0];
    while ((*tetrimino).cubes[4][0] < *size)
    {
        (*tetrimino).cubes[4][1] = (*tetrimino).cubes[3][1] + (*tetrimino).cubes[5][1];
        while ((*tetrimino).cubes[4][1] < *size)
        {
            if ((((*tetrimino).cubes[4][0] % 4 >= (*tetrimino).cubes[3][0]
                &&
                (grid[(*tetrimino).cubes[4][0] / 4] & (*tetrimino).binary_tetrimino >> ((*tetrimino).cubes[4][1] - (*tetrimino).cubes[3][1] + (((*tetrimino).cubes[4][0] - (*tetrimino).cubes[3][0]) % 4 * 16))) == 0) 
                
                ||
                
                ((*tetrimino).cubes[4][0] % 4 < (*tetrimino).cubes[3][0]
                &&
                (grid[(*tetrimino).cubes[4][0] / 4] & (*tetrimino).binary_tetrimino << (((*tetrimino).cubes[3][0] - (*tetrimino).cubes[4][0] % 4) * 16 - ((*tetrimino).cubes[4][1] - (*tetrimino).cubes[3][1]))) == 0))
                
                &&
                
                fits_entire_grid(grid, (*tetrimino).cubes))
                return (1);
            (*tetrimino).cubes[4][1]++;
        }
        (*tetrimino).cubes[4][0]++;
    }
    return (0);
}

static int    recursor(struct s_tetrimino *tetriminos, const short int const_i, uint64_t *grid, short int *size)
{
    short int   i;

    i = first_unplaced(tetriminos, const_i); // norm-conforming? idk if variables need to be initialized right after being declared
    if (i == 26 && !(tetriminos[const_i].binary_tetrimino != 0 && tetriminos[const_i].placed == 0)) // this signifies success
        return (1);
    if (const_i == 26) // this signifies a dead-end
        return (0);
    tetriminos[const_i].cubes[5][0] = tetriminos[const_i].cubes[3][0];
    while (tetriminos[const_i].cubes[3][0] + tetriminos[const_i].cubes[5][0] < *size)
    {
        tetriminos[const_i].cubes[5][1] = tetriminos[const_i].cubes[3][1];
        while (tetriminos[const_i].cubes[3][1] + tetriminos[const_i].cubes[5][1] < *size)
        {
            if (can_fit(&tetriminos[const_i], grid, size))
            {
                place_tetri(&tetriminos[const_i], grid);
                while (i < 26)
                {
                    if (recursor(tetriminos, i, grid, size))
                        return (1);
                    i = next_unplaced(tetriminos, i);
                }
                if (first_unplaced(tetriminos, i) == 26 && !(tetriminos[const_i].binary_tetrimino != 0 && tetriminos[const_i].placed == 0))
                    return (1);
                remove_tetri(&tetriminos[const_i], grid); // in dit geval moet ie weer can fit doen met een offset in [5][0] en/of [5][1]
            }
            tetriminos[const_i].cubes[5][1]++;
        }
        tetriminos[const_i].cubes[5][0]++;
    }
    return (recursor(tetriminos, next_unplaced(tetriminos, const_i), grid, size));
}

void        zeewier(struct s_tetrimino *tetriminos, uint64_t *grid, short int *size)
{
    short int   i;

    *size = 0;
    while (tetriminos[*size].binary_tetrimino != 0)
        (*size)++;
    *size = (short int)ft_sqrt(*size * 4);
    grid_setter(grid, size);
    while (*size <= 16)
    {
        i = 0;
        while (tetriminos[i].binary_tetrimino != 0 && i < 26)
        {
            if(recursor(tetriminos, i, grid, size))
                return ;
                i++;
        }
        (*size)++;
        grid_setter(grid, size);
    }
}