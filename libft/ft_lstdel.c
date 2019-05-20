/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 16:24:12 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/04/08 16:44:25 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	if ((*alst)->next)
	{
		*alst = (*alst)->next;
		ft_lstdel(alst, del);
	}
	free(*alst);
	*alst = NULL;
}
