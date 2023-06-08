/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:58 by dshushku          #+#    #+#             */
/*   Updated: 2023/01/26 02:59:59 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		c;

	if (n == 0)
		return (0);
	c = 0;
	while (c < n - 1 && s1[c] != 0 && s2[c] != 0 && s1[c] == s2[c])
		c++;
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
