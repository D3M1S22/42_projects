/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:37:34 by dshushku          #+#    #+#             */
/*   Updated: 2023/04/13 17:23:43 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_read_line(char *s, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		rd_bytes;

	rd_bytes = 1;
	while (!ft_strchr(s, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
			return ((void *)0);
		buff[rd_bytes] = '\0';
		s = ft_strjoin(s, buff);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	str[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = *ft_read_line(str, fd);
	if (str[fd])
		return ((void *)0);
	next_line = ft_get_line(str);
	str[fd] = *ft_shift_line(str);
	return (next_line);
}
