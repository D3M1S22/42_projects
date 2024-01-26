// strncmp input + '=' on envp matrix
#include "minishell.h"

char    **ft_unset(char **envp, char *unset_var)
{
    char    **updated_envp;
    int     i;

    unset_var = ft_strjoin(unset_var, "=");
    i = -1;
    while(envp[++i])
    {
        if (ft_strncmp(envp[i], unset_var, strlen(unset_var)) == 0)
            return(updated_envp = ft_cp_env(envp, 1, unset_var));
    }
    return(envp);
}