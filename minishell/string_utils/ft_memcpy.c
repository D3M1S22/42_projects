/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:58:36 by dshushku          #+#    #+#             */
/*   Updated: 2024/01/24 01:39:34 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
