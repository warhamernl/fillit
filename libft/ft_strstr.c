/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-wint <kde-wint@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 15:33:17 by kde-wint      #+#    #+#                 */
/*   Updated: 2019/04/11 10:03:55 by kde-wint      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		if (*haystack == needle[i])
			while (haystack[i] == needle[i] || !needle[i])
			{
				if (!needle[i])
					return ((char *)haystack);
				i++;
			}
		haystack++;
	}
	return (NULL);
}
