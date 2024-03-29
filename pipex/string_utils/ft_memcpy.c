/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:58:36 by dshushku          #+#    #+#             */
/*   Updated: 2023/06/21 15:05:15 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*source;
	char		*dest;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	source = src;
	dest = dst;
	while (n--)
		*dest++ = *source++;
	return (dst);
}
