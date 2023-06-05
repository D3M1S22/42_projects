#include "../include/pipex.h"

int count_digits(int num)
{
  int count;

  count = 1;
  if (num < 0)
  {
    count++;
    num = -num;
  }
  while (num /= 10)
    count++;
  return (count);
}

void fill_string(int num, char *str, int index)
{
  if (num / 10)
  {
    fill_string(num / 10, str, index - 1);
  }
  str[index] = '0' + num % 10;
}

char *ft_int_to_str(int num)
{
  int size;
  int index;
  char *str;

  size = count_digits(num);
  str = (char *)malloc((size + 1) * sizeof(char));
  if (!str)
    msg_error("Memory allocation failed\n");
  index = size - 1;
  str[size--] = '\0';
  if (num < 0)
  {
    str[0] = '-';
    num = -num;
  }
  fill_string(num, str, index);
  return (str);
}
