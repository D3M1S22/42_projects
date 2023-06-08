/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:24 by dshushku          #+#    #+#             */
/*   Updated: 2023/01/26 02:59:25 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int		i;
	char				*ret;

	i = 0;
	while (s1[i])
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return ((void *)0);
	ret[i++] = '\0';
	i--;
	while (i--)
		ret[i] = s1[i];
	return (ret);
}
