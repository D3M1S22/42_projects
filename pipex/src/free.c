/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:13:45 by dshushku          #+#    #+#             */
/*   Updated: 2023/06/21 15:22:15 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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

void	free_pipex(t_pipex *pipex)
{
	free_f_cmd(pipex->cmd_paths);
	free(pipex->tube);
	free(pipex->pids);
	free_cmds(pipex->cmds, pipex->n_cmds);
	close(pipex->infile);
	if (pipex->here_doc == 1)
		unlink(".heredoc_tmp");
	close(pipex->outfile);
	close_log_files(pipex);
	free(pipex->log_files);
	free(pipex);
	exit(0);
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (++i < (pipex->n_pipes))
		close(pipex->tube[i]);
}

void	free_parse(char *tmp, char *command)
{
	if (tmp)
		free(tmp);
	if (command)
		free(command);
}
