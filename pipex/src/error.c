/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:13:36 by dshushku          #+#    #+#             */
/*   Updated: 2023/06/21 15:22:31 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_error(char *err, int to_free)
{
	perror(err);
	if (to_free == 1)
		free(err);
	exit(1);
}

void	dup_handle(int tube, int pos)
{
	if (dup2(tube, pos) == -1)
		msg_error("dup 2 error\n", 0);
}

void	handle_waitpid(pid_t pid)
{
	if (waitpid(pid, NULL, 0) == -1)
		msg_error("waitpid error\n", 0);
}
