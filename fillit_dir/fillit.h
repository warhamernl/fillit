/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:52:49 by kde-wint       #+#    #+#                */
/*   Updated: 2019/05/22 14:48:31 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
//# include <libft.a> // is dit nodig en toegestaan?

typedef struct  s_tree
{
    char        name;
    void        *content;
    size_t      size;
    s_tree      *next;
    s_tree      *prev;
    s_tree      *left;
    s_tree      *right;
}               t_tree;

#endif
