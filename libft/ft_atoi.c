/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:56:51 by dshushku          #+#    #+#             */
/*   Updated: 2023/01/26 02:56:52 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	c;
	int	sign;
	int	r;

	c = 0;
	sign = 1;
	r = 0;
	while (str[c] != 0 && ((str[c] >= 9 && str[c] <= 13) || str[c] == 32))
		c++;
	if (str[c] != 0 && (str[c] == '-' || str[c] == '+'))
	{
		if (str[c] == '-')
			sign = -1;
		c++;
	}
	while (str[c] != 0 && str[c] >= '0' && str[c] <= '9')
	{
		r = r * 10 + (str[c] - 48);
		c++;
	}
	r *= sign;
	return (r);
}
