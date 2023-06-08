/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 03:00:12 by dshushku          #+#    #+#             */
/*   Updated: 2023/01/29 12:36:40 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*save;
	char	ch;

	ch = (char)c;
	save = NULL;
	while (*str)
	{
		if ((char)*str == ch)
			save = (char *)str;
		++str;
	}
	if (*str == ch)
		return ((char *)str);
	return (save);
}
