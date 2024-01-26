#include "../include/minishell.h"

// RETURNS A COPY OF ENVP && HANDLES MODIFICATION
char	**ft_cp_env(char **envp, int f, char *str)
{
	char 	**cp_env;
	int		i;
	int		j;

	j = -1;
	i = 0;
	while(envp[i] != NULL)
		i++;
	cp_env = malloc((i +( 1 - (f))) * sizeof(char*));
	while(++j < i)
	{
		if (f == 1 && str && ft_strncmp(envp[j], str, strlen(str)) == 0)
			continue;
		cp_env[j] = ft_strdup(envp[j]);
	}
	if (f == -1 && str)
	{
		cp_env[++j] = str;
		j++;
	}
	cp_env[j] = NULL;
	return(cp_env);
}
