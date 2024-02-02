/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:13:14 by dshushku          #+#    #+#             */
/*   Updated: 2024/01/27 17:03:57 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>

void	read_pipes(int pipe, int file)
{
	char	buffer[4096];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(pipe, buffer, sizeof(buffer));
		if (bytes_read == -1)
			msg_error("error reading", 0);
		if (write(file, buffer, bytes_read) != bytes_read)
			msg_error("error writing", 0);
	}
}

static void	sub_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void pre_executer(t_pipex *pipex, char **envp, int pid_n){
	
}
// infile, fd_arrays, cmds, n_pipes, envp, pid_n, outfile
void	child_work(char *read_line, int *fd_arrays, t_cmd **cmds,int n_cmds, int n_pipes, char **envp, int pid_n)
{
	printf("%d", pid_n);
	if (pid_n == 0)
	{
		printf("just one argument");
		sub_dup2(0, fd_arrays[1]);
	}

	if(n_cmds == 1){
		close_pipes(n_pipes, fd_arrays);  // fd_arrays, n_pipes
		execve(cmds[pid_n]->cmd, cmds[pid_n]->f_cmd, envp);
	}
	if (pid_n == n_cmds - 1)
		sub_dup2(fd_arrays[2 * pid_n - 2], 1);
	else
		sub_dup2(fd_arrays[2 * pid_n - 2], fd_arrays[2 * pid_n + 1]);
	close_pipes(n_pipes, fd_arrays);
	execve(cmds[pid_n]->cmd, cmds[pid_n]->f_cmd, envp);
}
