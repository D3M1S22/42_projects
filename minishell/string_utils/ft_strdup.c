/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:24 by dshushku          #+#    #+#             */
/*   Updated: 2024/01/24 01:39:34 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*ret;

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
