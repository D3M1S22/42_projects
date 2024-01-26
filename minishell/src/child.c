/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:13:14 by dshushku          #+#    #+#             */
/*   Updated: 2024/01/25 17:43:19 by dshushku         ###   ########.fr       */
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

void	child_work(t_pipex *pipex, char **envp, int pid_n)
{
	// if (pid_n == 0)
	// 	sub_dup2(pipex->infile, pipex->tube[1]);
	// int fd_file1 = 14; open("filename", O_CREAT | O_APPEND ,00000644);
	// int fd_file2 = 10; open("filename", O_RDONLY);
	// if('<')
	// 	close(fd[0]);

	// 	dup2(fd[1], STDOUT_FILENO);
	// 	char buffer[100000000000000];
	// 	read(fd_file1, buffer, 100000000000000000)
	// 	printf("%s",buffer);
	// 	read(fd_file2, buffer, 100000000000000000)
	// 	printf("%s",buffer);
	// 	close(fd[1]);

	if(pipex->n_cmds == 1){
		close_pipes(pipex);
		execve(pipex->cmds[pid_n]->cmd, pipex->cmds[pid_n]->f_cmd, envp);
	}
	if (pid_n == pipex->n_cmds - 1)
		sub_dup2(pipex->tube[2 * pid_n - 2], pipex->outfile);
	else
		sub_dup2(pipex->tube[2 * pid_n - 2], pipex->tube[2 * pid_n + 1]);
	close_pipes(pipex);
	execve(pipex->cmds[pid_n]->cmd, pipex->cmds[pid_n]->f_cmd, envp);
}
