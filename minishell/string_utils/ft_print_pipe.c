/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:05:21 by dshushku          #+#    #+#             */
/*   Updated: 2024/01/24 01:39:34 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_pipe(int pipe, int log_file)
{
	int		byte_r;
	int		i;
	char	*buffer;

	i = 0;
	buffer = malloc(sizeof(char *) * 10000000);
	if (!buffer)
		msg_error("Errore buffer\n", 0);
	byte_r = read(pipe, &buffer[i++], 255);
	while (byte_r > 0)
		byte_r = read(pipe, &buffer[i++], 255);
	ft_putstr(buffer, log_file);
	free(buffer);
}
