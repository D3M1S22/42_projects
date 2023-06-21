/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:11:01 by dshushku          #+#    #+#             */
/*   Updated: 2023/06/21 15:21:23 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_putchr(int c, int log)
{
	write(log, &c, 1);
	return (1);
}

int	ft_putstr(char *str, int log)
{
	int	i;

	i = -1;
	if (!str)
	{
		write(log, "(null)", 6);
		return (6);
	}
	while (str[++i])
		ft_putchr(str[i], log);
	return (i);
}
