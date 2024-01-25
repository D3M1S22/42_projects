/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:03:31 by damianoshus       #+#    #+#             */
/*   Updated: 2024/01/24 01:39:34 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	intlen(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		len;
	long	num;

	num = n;
	len = intlen(num);
	r = malloc(sizeof(char) * len + 1);
	if (!r)
		return ((void *)0);
	r[len--] = 0;
	if (num == 0)
		r[0] = '0';
	if (num < 0)
	{
		num *= -1;
		r[0] = '-';
	}
	while (num > 0)
	{
		r[len] = (num % 10) + 48;
		num /= 10;
		len--;
	}
	return (r);
}
