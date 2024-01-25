/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:34 by dshushku          #+#    #+#             */
/*   Updated: 2024/01/24 01:39:34 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = -1;
	while (s[++i] != 0)
		continue ;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	size_t	l1;
	size_t	l2;
	int		i;

	if (!s1 || !s2)
		return ((void *)0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	r = malloc(sizeof(char) * (l1 + l2 + 1));
	if (r == (void *)0)
		return ((void *)0);
	i = -1;
	while (s1[++i])
		r[i] = s1[i];
	i = -1;
	while (s2[++i])
		r[l1++] = s2[i];
	r[l1] = 0;
	return (r);
}
