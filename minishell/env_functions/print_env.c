#include "../include/minishell.h"

// PRINTS AN ENV VARIABLE
void	ft_print_env_var(char *env_var, char **envp)
{
	int env_l;
	env_l = ft_strlen(env_var);

	while (envp != NULL && ft_strncmp(env_var, *envp, env_l))
		envp++;
	printf("%s\n", *envp);
}
// PRINTS ENV
void	ft_print_env(char **envp)
{
	while (envp != NULL)
    {
		envp++;
	    printf("%s\n", *envp);
    }
}