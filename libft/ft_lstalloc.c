/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/06 12:24:28 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/07/06 12:32:40 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstalloc(size_t content_size)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	tmp->content = (void *)malloc(sizeof(unsigned char) * content_size);
	tmp->content_size = content_size;
	tmp->next = NULL;
	return (tmp);
}
