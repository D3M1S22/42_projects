/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:07:15 by dshushku          #+#    #+#             */
/*   Updated: 2023/06/21 15:21:00 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_putnbr(int nb, int log)
{
	int	c;

	c = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648", log));
	if (nb < 0)
	{
		c += ft_putchr('-', log);
		nb *= -1;
		c += ft_putnbr(nb, log);
	}
	else if (nb < 10)
		c += ft_putchr(nb + 48, log);
	else
	{
		c += ft_putnbr(nb / 10, log);
		c += ft_putchr((nb % 10) + 48, log);
	}
	return (c);
}
