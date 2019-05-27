/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:52:49 by kde-wint       #+#    #+#                */
/*   Updated: 2019/05/27 18:13:31 by mlokhors      ########   odam.nl         */
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

/*
typedef struct  s_uint256
{
    uint64_t value[4];
}                   t_uint256;

 typedef uint64_t t_uint256[4]; dit is ook mogelijk maar minder expliciet
*/

void	opening(char *str, uint64_t *tetrimino);

void print_binary(unsigned short int number); // remove before turning in

#endif
