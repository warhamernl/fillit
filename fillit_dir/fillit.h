/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:52:49 by kde-wint       #+#    #+#                */
/*   Updated: 2019/07/06 12:29:50 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>

struct					s_tetrimino
{
	unsigned long long	binary_tetrimino;
	short int			cubes[5][2];
	short int			placed;
};

int						opening(char *str, struct s_tetrimino tetriminos[27]);
void					cubes_offsetter(unsigned long long tetrimino,
	short int cubes[5][2]);
short int				height_initializer(struct s_tetrimino *tetriminos,
	short int i, short int size);
short int				width_initializer(struct s_tetrimino *tetriminos,
	short int i, short int size, short int *w_initialized);
void					place_tetri(struct s_tetrimino *tetrimino,
	unsigned long long *grid);
void					remove_tetri(struct s_tetrimino *tetriminos,
	unsigned long long *grid);
void					algorithm(struct s_tetrimino *tetriminos,
	unsigned long long *grid, short int *size);
short int				next_unplaced(struct s_tetrimino *tetriminos,
	short int i);
unsigned long long		shift(unsigned long long tetro);
void					total_read(int i, int bytes_read);

#endif
