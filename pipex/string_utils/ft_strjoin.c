#include "../include/pipex.h"

char *ft_strjoin(char const *s1, char const *s2)
{
  char *j_str;
  size_t i;
  size_t j;

  j_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
  if (!j_str)
    return (NULL);
  i = 0;
  while (s1[i] != '\0')
  {
    j_str[i] = s1[i];
    i++;
  }
  j = 0;
  while (s2[j] != '\0')
  {
    j_str[i] = s2[j];
    i++;
    j++;
  }
  j_str[i] = '\0';
  return (j_str);
}