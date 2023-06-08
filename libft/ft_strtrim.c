/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 03:00:16 by dshushku          #+#    #+#             */
/*   Updated: 2023/01/26 03:00:16 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	contains(char const *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

int	get_start(char const *s1, char const *set)
{
	int	i;

	i = -1;
	while (s1[++i])
	{
		if (contains(set, s1[i]))
			continue ;
		return (i);
	}
	return (-1);
}

int	get_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1);
	i--;
	while (s1[i])
	{
		if (contains(set, s1[i]))
		{
			i--;
			continue ;
		}
		return (i + 1);
	}
	return (-1);
}

char	*fill_result(char const *s1, int start, int end, char *r)
{
	int	i;

	i = -1;
	start--;
	while (s1[++start] && start < end)
		r[++i] = s1[start];
	r[++i] = 0;
	return (r);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*r;

	if (!s1)
		return ((void *)0);
	if (!set)
	{
		end = ft_strlen(s1);
		r = malloc(sizeof(char) * end + 1);
		if (r == (void *)0)
			return ((void *)0);
		return (fill_result(s1, 0, end, r));
	}
	start = get_start(s1, set);
	if (start == -1)
		return (ft_strdup(""));
	end = get_end(s1, set);
	r = malloc(sizeof(char) * (end - start + 1));
	if (r == (void *)0)
		return ((void *)0);
	return (fill_result(s1, start, end, r));
}
