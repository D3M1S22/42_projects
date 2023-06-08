/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:59:53 by dshushku          #+#    #+#             */
/*   Updated: 2023/01/26 02:59:53 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		c;
	char	*r;

	c = -1;
	if (!s)
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	r = ft_strdup(s);
	if (!r)
		return (r = (void *)0);
	while (s[++c])
		r[c] = f(c, s[c]);
	r[c] = '\0';
	return (r);
}
