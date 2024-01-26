/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:03:20 by damianoshus       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/25 17:56:03 by federico         ###   ########.fr       */
=======
/*   Updated: 2024/01/26 14:38:16 by dshushku         ###   ########.fr       */
>>>>>>> 913d1bb42af0ad5e57d46faa2f7eb4abb85e64fd
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void test(int a)
{
	printf("%d\n", a);
}


int	main(int argc, char const **argv, char **const envp)
{
	// int		f1;
	// int		f2;
	t_pipex	*pipex_s;
	// char *args[] = {"infile", ">", "damiano.txt", NULL};
	// execve("/bin/cat", args , NULL);
	// if (argc < 5)
	// {
	// 	msg("Not enough arguments\n");
	// 	return (1);
	// }
	
	pipex_s = (t_pipex *)malloc(sizeof(t_pipex));
	// if (handle_files(argv[1], pipex_s, argv[2], argv[argc - 1]) == 1)
	// {
	// 	free(pipex_s);
	// 	return (-1);
	// }
	char *res;
	while(1)
	{
		res = readline("Minishell >");
		// printf("%s\n", res);
		// pipex_s->here_doc = 0; // TO REMOVE
		// pipex_s->n_cmds = argc - 3 - pipex_s->here_doc;
		// pipex_s->n_pipes = 2 * (pipex_s->n_cmds - 1);
		// pipex_s->log_files = create_log_files(pipex_s->n_cmds);
		pipex(pipex_s, res, envp);
	}
<<<<<<< HEAD
	free(res);
		// exit(0);
=======
	// free(res);
>>>>>>> 913d1bb42af0ad5e57d46faa2f7eb4abb85e64fd

	return (0);
}
