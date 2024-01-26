/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:14:43 by dshushku          #+#    #+#             */
/*   Updated: 2024/01/26 01:09:36 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <malloc/_malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>
#include <unistd.h>

t_cmd	**check_cmds(t_cmd **cmds, int ncmds)
{
	int	i;

	i = -1;
	while (++i < ncmds)
	{
		if (!cmds[i]->cmd)
		{
			free_cmds(cmds, ncmds);
			msg_error(ERR_CMD, 0);
		}
	}
	return (cmds);
}

t_cmd	**malloc_cmds(size_t size)
{
	t_cmd	**tmp;

	tmp = (t_cmd **)malloc(size);
	if (!tmp)
		msg_error("Errore allocando memoria\n", 0);
	return (tmp);
}

int ft_handle_access(t_cmd *cmd, char *command, char *tmp){
	cmd->cmd = ft_strdup(command);
	cmd->error = 0;
	free_parse(tmp, command);
	if (access(cmd->cmd, 0) == 0)
		return (1);
	cmd->error = 1;
	return 0;
}


t_cmd	**ft_parse_cmd(char **argv, int ncmds, char **paths)
{
	t_cmd	**cmds;
	char	*tmp;
	char	*command;
	int		i;
	int		j;

	i = -1;
	cmds = malloc_cmds(ncmds * sizeof(t_cmd *));
	while (++i < ncmds && argv[i])
	{
		cmds[i] = malloc(sizeof(t_cmd));
		cmds[i]->f_cmd = ft_split(argv[i], ' ');
		j = -1;
		while (paths[++j])
		{
			tmp = ft_strjoin(paths[j], "/");
			command = ft_strjoin(tmp,cmds[i]->f_cmd[0]);
			if(ft_handle_access(cmds[i], command, tmp))
				break;
		}
	}
	return (check_cmds(cmds, ncmds));
}

char	**ft_parse_paths(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (ft_split(*envp, ':'));
}

void tokenize_redir(t_cmd *cmd)
{
	int j;
	int i;

	j = 0;
	while (cmd->f_cmd[j] != (void *)0)
		j++;	
	cmd->redirection = malloc((j + 1) * sizeof(char *));
	j = 0;
	i = -1;
	while(cmd->f_cmd[++j] != (void *)0){
		if(cmd->f_cmd[j][0] == '\'' || cmd->f_cmd[j][0] == '\"')
			break;
		else if(ft_strncmp(cmd->f_cmd[j], "<<", 2) == 0){
			cmd->redirection[++i] = ft_strdup(cmd->f_cmd[j]);
		}
		else if(ft_strncmp(cmd->f_cmd[j], "<", 1) == 0){
			write(1, "2\n",2);
			cmd->redirection[++i] = ft_strdup(cmd->f_cmd[j]);
		}
		else if (ft_strncmp(cmd->f_cmd[j], ">>", 2) == 0){
			printf("3\n");
			cmd->redirection[++i] = ft_strdup(cmd->f_cmd[j]);
		}
		else if (ft_strncmp(cmd->f_cmd[j], ">", 1) == 0){
			printf("4\n");
			cmd->redirection[++i] = ft_strdup(cmd->f_cmd[j]);
		}
		else{
			// cmd->redirection[++i] = NULL;
		}
	}
}

void ft_test(char *cmd){
	printf("%s\n", cmd);
}

void tokenize_builtin(t_cmd *cmd)
{
	int j;
	int i;

	i = 0;
	j = 0;
	while(cmd->f_cmd[++j] != (void *)0)
		if(cmd->f_cmd[j][0] == '\'' || cmd->f_cmd[j][0] == '\"')
			break;
		else if(ft_strncmp(cmd->f_cmd[j], "cd", 2) == 0)
			cmd->builtin = ft_test;
		else if(ft_strncmp(cmd->f_cmd[j], "echo", 4) == 0)
			cmd->builtin = ft_test;
		else if (ft_strncmp(cmd->f_cmd[j], "pwd", 3) == 0)
			cmd->builtin = ft_test;
		else if (ft_strncmp(cmd->f_cmd[j], "exit", 4) == 0)
			cmd->builtin = ft_test;
		else if (ft_strncmp(cmd->f_cmd[j], "export", 6) == 0)
			cmd->builtin = ft_test;
		else if (ft_strncmp(cmd->f_cmd[j], "unset", 5) == 0)
			cmd->builtin = ft_test;
		else if (ft_strncmp(cmd->f_cmd[j], "env", 3) == 0)
			cmd->builtin = ft_test;
		else
			cmd->builtin = NULL;
}

void tokenizer(t_cmd **cmds, int n_cmds)
{
	int i;
	int j;

	i = -1;
	while (++i < n_cmds) {
		tokenize_redir(cmds[i]);
		// tokenize_builtin(cmds[i]);
	}

}

void	pipex(t_pipex *pipex, const char *argv, char **envp)
{
	// int	i;
	char **piped_str = ft_split(argv, '|');
	int i = 0;
	while (piped_str[i] != (void *)0) {
		// printf("%s\n", piped_str[i]);
		i++;
	}
	pipex->n_cmds = i;
	pipex->cmd_paths = ft_parse_paths(envp);
	pipex->cmds = ft_parse_cmd(piped_str,
			pipex->n_cmds, pipex->cmd_paths);
	tokenizer(pipex->cmds, pipex->n_cmds);
	


	int j = -1;
	while (++j<i) {
		// printf("pipex->cmds[%d] = %s\n, isError %d ", j, pipex->cmds[j]->cmd,pipex->cmds[j]->error);
		int k = -1;
		while (pipex->cmds[j]->f_cmd[++k]!= (void *)0){
			int m = -1;
			while (pipex->cmds[j]->redirection[++m] != ){
				printf("D\n");
				printf("%s\n", pipex->cmds[j]->redirection[m]);
			}
		}
			// printf("pipex->cmds[%d]->f_cmd[%d] =  %s\n",j, k, pipex->cmds[j]->f_cmd[k]);
	}
	
	// i=0;
	// while (piped_str[i] != (void *)0) {
	// 	free(piped_str[i]);
	// }
	// free(piped_str);
	// int e = execve(pipex->cmds[0]->cmd, pipex->cmds[0]->f_cmd, envp);
	// printf("execve res : %d\n", e);
	// return ;
	// pipex->tube = (int *)malloc(sizeof(int) * (pipex->n_pipes));
	// // i = -1;
	// while (++i < pipex->n_cmds - 1)
	// 	if (pipe(pipex->tube + 2 * i) == -1)
	// 		free_pipex(pipex);
	// pipex->pids = (int *)malloc(pipex->n_cmds * sizeof(int));
	// i = -1;
	// while (++i < pipex->n_cmds)
	// {
	// 	pipex->pids[i] = fork();
	// 	if (pipex->pids[i] == -1)
	// 		msg_error("pid error", 0);
	// 	else if (!pipex->pids[i])
	// 		child_work(pipex, envp, i);
	// }
	// close_pipes(pipex);
	// handle_waitpid(-1);
	free_pipex(pipex);
}
