/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:57:39 by dshushku          #+#    #+#             */
/*   Updated: 2023/01/26 02:57:39 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
