/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_short.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:37:20 by dshushku          #+#    #+#             */
/*   Updated: 2023/03/20 13:37:25 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1

char	*get_next_line_short(int fd)
{
	char	*buf;

	buf = malloc(10000000 * sizeof(char *));
	for (int byte_rd = read(fd, &buf[0], 1),
				j = 1;
			byte_rd > 0;
			byte_rd = read(fd, &buf[j], 1), j++)
		if (buf[j - 1] == '\n')
		{
			buf[j] = '\0';
			break ;
		}
	return (buf);
}

// int main(void)
// {
//   char *s;
//   int fd = open("./tests/test3.txt", O_RDONLY);
//   s=get_next_line_short(fd);
//   printf("%s",s);
//   s=get_next_line_short(fd);
//   printf("%s",s);
//   s=get_next_line_short(fd);
//   printf("%s",s);
//   s = get_next_line_short(fd);
//   printf("%s", s);
//   s=get_next_line_short(fd);
//   printf("%s",s);
//   return (0);
// }
