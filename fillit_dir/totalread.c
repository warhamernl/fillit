/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   totalread.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlokhors <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 08:08:02 by mlokhors      #+#    #+#                 */
/*   Updated: 2019/07/04 08:25:42 by mlokhors      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	total_read(int i, int bytes_read)
{
	if (bytes_read != ((i * 21) - 1))
	{
		write(1, "error\n", 6);
		exit(-1);
	}
}
