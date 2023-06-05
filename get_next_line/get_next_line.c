#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char *ft_read_line(char *s, int fd)
{
  char *buff;
  int rd_bytes;

  buff = malloc(BUFFER_SIZE * sizeof(char) + 1);
  rd_bytes = 1;
  while (!ft_strchr(s, '\n') && rd_bytes != 0)
  {
    rd_bytes = read(fd, buff, BUFFER_SIZE);
    if (rd_bytes == -1)
    {
      free(buff);
      return (NULL);
    }
    buff[rd_bytes] = '\0';
    s = ft_strjoin(s, buff);
  }
  free(buff);
  return (s);
}

char *get_next_line(int fd)
{
  char *next_line;
  static char *str;

  if (fd < 0 || BUFFER_SIZE <= 0)
    return (0);
  str = ft_read_line(str, fd);
  if (!str)
    return (NULL);
  next_line = ft_get_line(str);
  str = ft_shift_line(str);
  return (next_line);
}
