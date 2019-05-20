/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtolower.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/13 15:45:53 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/04/13 17:29:31 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_tolowerchar(char c)
{
	return ((char)ft_tolower((int)c));
}

char		*ft_strtolower(const char *s)
{
	return (ft_strmap(s, ft_tolowerchar));
}
