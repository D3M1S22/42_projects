#include "../include/minishell.h"

char	*ft_pwd(void)
{
	char	*buffer;
	char	*s;
	int		i;

	i = 0;
	buffer = (char *)malloc(10000000);
	if (!buffer)
		return (0);
	getcwd(buffer, 10000000);
	while (buffer[i] != '\0')
		i++;
	s = malloc(sizeof(char) * i);
	i = -1;
	while (buffer[++i] != '\0')
		s[i] = buffer[i];
	s[i] = '\0';
	free(buffer);
	return (s);
}