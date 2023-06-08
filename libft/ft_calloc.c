/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:57:05 by dshushku          #+#    #+#             */
/*   Updated: 2023/01/28 18:56:30 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if ((double)count / 2 + (double)size / 2 == SIZE_MAX)
		return (NULL);
	if (count == 0)
		count = 1;
	if (size == 0)
		size = 1;
	ret = malloc(size * count);
	if (!ret)
		return ((void *)0);
	ft_bzero(ret, count * size);
	return (ret);
}
