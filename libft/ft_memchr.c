/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:58:27 by dshushku          #+#    #+#             */
/*   Updated: 2023/01/26 02:58:28 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	int	i;

	i = -1;
	while (n--)
		if ((unsigned char)((char *)s)[++i] == (unsigned char)c)
			return ((void *)&s[i]);
	return ((void *)0);
}
