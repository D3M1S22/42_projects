#include "../include/minishell.h"

// HANDLE -N
void	ft_echo(t_cmd *cmd)
{
	int		i;
	int		j;
	char	*str;

	j = 1;
	i = 0;
	while (cmd->f_cmd[j])
		j++;
	while (++i <= j)
	{
		str = str_join(cmd->f_cmd[i], cmd->f_cmd[i + 1]);
	}
	printf("%s", str);
	free(str);
}