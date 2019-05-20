/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 15:14:55 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/04/11 11:01:58 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;

	ret = (void *)malloc(sizeof(unsigned char) * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
