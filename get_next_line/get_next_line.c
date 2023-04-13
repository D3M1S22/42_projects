/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:37:56 by dshushku          #+#    #+#             */
/*   Updated: 2023/03/20 13:37:56 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
			return (NULL);
		buff[rd_bytes] = '\0';
		s = ft_strjoin(s, buff);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_line(str, fd);
	if (!str)
		return (NULL);
	next_line = ft_get_line(str);
	str = ft_shift_line(str);
	return (next_line);
}
