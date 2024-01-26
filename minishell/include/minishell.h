/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshushku <dshushku@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 01:41:37 by dshushku          #+#    #+#             */
/*   Updated: 2024/01/26 13:52:43 by dshushku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../gnl/get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
#	include <readline/readline.h>
#	include <readline/history.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

// typedef struct s_args
// {
// 	void *arg1;
// 	void *arg2;
// 	void *arg3;
// } t_args;

typedef struct s_cmd
{
	char	**f_cmd;
	char	*cmd;
	int		error;
	void	(*builtin)(); // CALL TO FUNCTION ((void (*)(int))builtin)
	char	**redirection;
}			t_cmd;

typedef struct s_pipex
{
	int		*pids;
	int		*tube;
	int		infile;
	int		outfile;
	char	**cmd_paths;
	t_cmd	**cmds;
	int		*log_files;
	int		n_cmds;
	int		n_pipes;
	int		here_doc;
}			t_pipex;

void		pipex(t_pipex *pipex, const char *argv, char **envp);

// SETUP
int			handle_files(const char *infile, t_pipex *pipex,
				const char *delimiter, const char *outfile);
void		here_doc(const char *argv, t_pipex *pipex);
//------

// STRING UTILS
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *src);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_putnbr(int nb, int log);
int			ft_putchr(int c, int log);
int			ft_putstr(char *str, int log);
void		ft_print_pipe(int pipe, int log_file);
char		*ft_itoa(int n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void handle_quotes(const char *s, int *i, char quote_found, int *start);
char	*ft_substr(char const *s, unsigned int start, size_t len);
//-------------

// FREE UTILS
void		free_cmds(t_cmd **cmds, int ncmd);
void		free_pipex(t_pipex *pipex);
void		close_pipes(t_pipex *pipex);
void		free_parse(char *tmp, char *command, char* str_mod);
//-----------

// CHILD
void		child_work(t_pipex *pipex, char **envp, int pid_n);
//-----

// DEBUG
int			*create_log_files(int n_cmds);
void		close_log_files(t_pipex *pipex);
//------

// ERROR
int			msg(char *err);
void		msg_error(char *err, int to_free);
void		dup_handle(int tube, int pos);
void		handle_waitpid(pid_t pid);
//-----

#endif