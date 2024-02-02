/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:13:45 by dshushku          #+#    #+#             */
/*   Updated: 2024/01/27 17:09:24 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>

void	free_f_cmd(char **f_cmd)
{
	int	i;

	i = -1;
	while (f_cmd[++i])
		free(f_cmd[i]);
	free(f_cmd);
}

void	free_cmds(t_cmd **cmds, int ncmd)
{
	int	i;

	i = -1;
	while (++i < ncmd)
	{
		free_f_cmd(cmds[i]->f_cmd);
		free(cmds[i]->cmd);
		free(cmds[i]);
	}
	free(cmds);
}

void	free_pipex()
{
	// free_f_cmd(pipex->cmd_paths);
	// // free(pipex->tube);
	// // free(pipex->pids);
	// free_cmds(pipex->cmds, pipex->n_cmds);
	// // close(pipex->infile);
	// // if (pipex->here_doc == 1)
	// // 	unlink(".heredoc_tmp");
	// // close(pipex->outfile);
	// // close_log_files(pipex);
	// // free(pipex->log_files);
	// free(pipex);
	exit(0);
}

void	close_pipes(int n_pipes, int *fd_arrays)
{
	int	i;

	i = -1;
	while (++i < (n_pipes))
		close(fd_arrays[i]);
}

void	free_parse(char *tmp, char *command, char* str_mod)
{
	if (tmp)
		free(tmp);
	if (command)
		free(command);
	if(str_mod)
		free(str_mod);
}
