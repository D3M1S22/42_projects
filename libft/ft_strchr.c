/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:19 by dshushku          #+#    #+#             */
/*   Updated: 2023/01/26 02:59:19 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	w;
	int		i;

	w = c;
	i = -1;
	while (s[++i] != 0)
		if (s[i] == w)
			return ((char *)s + i);
	if (s[i] == w)
		return ((char *)s + i);
	return ((void *)0);
}
