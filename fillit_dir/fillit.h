/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:52:49 by kde-wint       #+#    #+#                */
/*   Updated: 2019/05/23 16:30:31 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> // remove before uploading
# include "../libft/libft.h"

typedef struct      s_tree
{
    char            name;
    void            *content;
    size_t          size;
    struct s_tree   *next;
    struct s_tree   *prev;
    struct s_tree   *up;
    struct s_tree   *left;
    struct s_tree   *right;
}                   t_tree;

void	opening(char *str, unsigned short int *tetrimino);

void print_binary(unsigned short int number); // remove before turning in

#endif
