#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char *get_next_line(int fd);
char *ft_read_line(char *s, int fd);
char *ft_strchr(char *s, int c);
char *ft_strjoin(char *left_str, char *buff);
size_t ft_strlen(char *s);
char *ft_get_line(char *left_str);
char *ft_shift_line(char *left_str);

#endif