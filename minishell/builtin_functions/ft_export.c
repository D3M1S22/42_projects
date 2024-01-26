#include "../include/minishell.h"

char    **ft_export(char **envp, char *new_var)
{
    char	**updated_env;
    int		i;

	i = -1;
    while(new_var[++i])
    {
        if (new_var[i] == '=')
		{
            updated_env = ft_cp_env(envp, -1, new_var);
			return (updated_env);
		}
    }
	return (envp);
}