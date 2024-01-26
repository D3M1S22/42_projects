#include "../include/minishell.h"

// MODIFY ENV VARIABLE CONTENT
void	change_envp_var(char *env, char *new_content, char **envp)
{
	char	*tmp;
	int 	env_l;
	int		i;

	i = 0;
	tmp = ft_strjoin(env, new_content);
	env_l = ft_strlen(env);
	while (envp[i] && ft_strncmp(env, envp[i], env_l))
		i++;
	free(envp[i]);
	envp[i] = malloc(ft_strlen(tmp) * sizeof(char *)); 
	envp[i] = ft_strdup((const char*)tmp);
	free(tmp);
}



void	ft_cd(char **args, char **envp)
{
	char 	*old_pwd;
	char 	*new_pwd;

	old_pwd = ft_pwd();
	if (!args)
	{
		printf("error\n");
		return ;
	}
	if (args[1])
	{
		printf("cd: string not in pwd: %s\n", args[0]);
		return ;
	}
	if (chdir(args[0]) == -1)
	{
		printf("cd: no such file or directory: %s\n", args[0]);
		return ;
	}
	new_pwd = ft_pwd();
	change_envp_var("PWD=",new_pwd, envp);
	change_envp_var("OLDPWD=", old_pwd, envp);
	free(old_pwd);
	free(new_pwd);
}



