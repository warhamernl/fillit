/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:52:49 by kde-wint       #+#    #+#                */
/*   Updated: 2019/06/09 18:19:52 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
/* zijn defines voor CONTINUE ofzo een idee?*/

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h> // remove before submission

struct          s_tetrimino
{
    uint64_t    binary_tetrimino;
    short int   cubes[6][2];
    short int   placed; // this will track whether the tetrimino is currently in the grid
};

int             opening(char *str, struct s_tetrimino tetriminos[27]);
void            cubes_offsetter(uint64_t tetrimino, short int cubes[6][2]);
void            place_tetri(struct s_tetrimino *tetrimino, uint64_t *grid);
void	        remove_tetri(struct s_tetrimino *tetriminos, uint64_t *grid);
void            zeewier(struct s_tetrimino *tetriminos, uint64_t *grid, short int *size);
short int   	first_unplaced(struct s_tetrimino *tetriminos, const short int const_i); // should a const variable have a specific name? double check pls - Kim
short int   	next_unplaced(struct s_tetrimino *tetriminos, short int i);

#endif

/* before uploading, check:
    - forbidden libraries
    - forbidden functions
    - the norm extensively(with norm-PDF)
*/