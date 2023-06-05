#include "../include/pipex.h"

int ft_putchr(int c, int log)
{
  write(log, &c, 1);
  return (1);
}

int ft_putstr(char *str, int log)
{
  int i;

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