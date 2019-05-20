/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/20 14:52:49 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/05/20 14:52:50 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

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