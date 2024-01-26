/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 01:41:37 by dshushku          #+#    #+#             */
/*   Updated: 2024/01/26 13:53:05 by federico         ###   ########.fr       */
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

typedef struct s_cmd
{
	char	**f_cmd;
	char	*cmd;
	int error;
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
//-------------

// FREE UTILS
void		free_cmds(t_cmd **cmds, int ncmd);
void		free_pipex(t_pipex *pipex);
void		close_pipes(t_pipex *pipex);
void		free_parse(char *tmp, char *command);
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

//BUILTIN
void	ft_echo(t_cmd *cmd);
void	ft_cd(char **args, char **envp);
char	*ft_pwd(void);
void    ft_env(char **envp);
char    **ft_export(char **envp, char *new_var);
char    **ft_unset(char **envp, char *unset_var);
//-----

// ENV
char	**ft_cp_env(char **envp, int f, char *str);
void	ft_print_env(char **envp);
void	ft_print_env_var(char *env_var, char **envp);
//-----

#endif