/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:03:20 by damianoshus       #+#    #+#             */
/*   Updated: 2023/06/21 15:05:08 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char const **argv, char **const envp)
{
	int		f1;
	int		f2;
	t_pipex	*pipex_s;

	if (argc < 5)
	{
		msg("Not enough arguments\n");
		return (1);
	}
	pipex_s = (t_pipex *)malloc(sizeof(t_pipex));
	if (handle_files(argv[1], pipex_s, argv[2], argv[argc - 1]) == 1)
	{
		free(pipex_s);
		return (-1);
	}
	pipex_s->n_cmds = argc - 3 - pipex_s->here_doc;
	pipex_s->n_pipes = 2 * (pipex_s->n_cmds - 1);
	pipex_s->log_files = create_log_files(pipex_s->n_cmds);
	pipex(pipex_s, argv, envp);
}
