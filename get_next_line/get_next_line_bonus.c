#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char *ft_read_line(char *s, int fd)
{
  char buff[BUFFER_SIZE + 1];
  int rd_bytes;

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

char *get_next_line(int fd)
{
  char *next_line;
  static char *str[OPEN_MAX];

  if (fd < 0 || BUFFER_SIZE <= 0)
    return (0);
  str[fd] = ft_read_line(str, fd);
  if (!str)
    return (NULL);
  next_line = ft_get_line(str);
  str[fd] = ft_shift_line(str);
  return (next_line);
}
