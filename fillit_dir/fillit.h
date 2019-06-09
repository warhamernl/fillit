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
// zijn defines voor CONTINUE ofzo een idee?

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> // remove
# include "../libft/libft.h"

struct          s_tetrimino
{
    uint64_t    binary_tetrimino;
    short int   cubes[5][2];
};

void            opening(char *str, struct s_tetrimino tetriminos[27]);
void            cubes_offsetter(uint64_t tetrimino, short int cubes[5][2]);
void            place_tetri(struct s_tetrimino *tetrimino, uint64_t *grid);
void	        remove_tetri(struct s_tetrimino *tetriminos, short int i, uint64_t *grid);
void            zeewier(struct s_tetrimino *tetriminos, uint64_t *grid);

#endif

/* before uploading, check:
    - forbidden libraries
    - forbidden functions
    - the norm extensively(with norm-PDF)
*/
// void print_binary(unsigned short int number); // remove before turning in