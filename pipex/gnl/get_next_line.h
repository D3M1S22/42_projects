

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "../include/pipex.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		get_next_line(int fd, char **line);
size_t	strlen(const char *s);
int		find_nl(char *str);
char	*str_join(char *s1, char *s2);
char	*get_line(char *str);
char	*trim_rem(char *str);
int		some_error(char *str);
void free_rem(char *rem);
#endif
