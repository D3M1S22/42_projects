/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:14:24 by dshushku          #+#    #+#             */
/*   Updated: 2023/06/21 15:14:39 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_and_exit(char *buf)
{
	free(buf);
	exit(1);
}

int	handle_files(const char *infile, t_pipex *pipex, const char *delimiter,
		const char *outfile)
{
	pipex->here_doc = 0;
	if (!ft_strncmp("here_doc", infile, 9))
		pipex->here_doc = 1;
	if (pipex->here_doc == 0)
	{
		pipex->infile = open(infile, O_RDONLY);
		pipex->outfile = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	}
	else
	{
		here_doc(delimiter, pipex);
		pipex->outfile = open(outfile, O_CREAT | O_RDWR | O_APPEND, 0000644);
	}
	if (pipex->infile == -1)
		return (msg("error on infile"));
	if (pipex->outfile == -1)
		return (msg("error on outfile"));
	return (0);
}

void	here_doc(const char *argv, t_pipex *pipex)
{
	int		file;
	char	*buf;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		msg_error("errore nel here doc", 0);
	while (1)
	{
		write(1, "heredoc> ", 9);
		if (get_next_line(0, &buf) < 0)
			free_and_exit(buf);
		if (!ft_strncmp(argv, buf, ft_strlen(argv) + 1))
			break ;
		write(file, buf, ft_strlen(buf));
		write(file, "\n", 1);
		free(buf);
	}
	free(buf);
	close(file);
	pipex->infile = open(".heredoc_tmp", O_RDONLY);
	if (pipex->infile < 0)
	{
		unlink(".heredoc_tmp");
		msg_error("errore nel here doc", 0);
	}
}
