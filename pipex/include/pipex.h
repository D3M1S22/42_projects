/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:34:21 by mlazzare          #+#    #+#             */
/*   Updated: 2021/08/02 16:27:48 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
# include "../gnl/get_next_line.h"

#define ERR_INFILE "Infile"
#define ERR_OUTFILE "Outfile"
#define ERR_INPUT "Invalid number of arguments.\n"
#define ERR_PIPE "Pipe"
#define ERR_CMD "Command not found\n"

static int processes = -1;

typedef struct s_cmd
{
  char **f_cmd;
  char *cmd;
} t_cmd;

typedef struct s_pipex
{
  int *pids;
  int *tube;
  int infile;
  int outfile;
  char **cmd_paths;
  t_cmd **cmds;
  int *log_files;
  int n_cmds;
  int n_pipes;
  int here_doc;
} t_pipex;

void pipex(t_pipex *pipex, const char **argv, char **envp);

// SETUP
int handle_files(const char *infile, t_pipex* pipex, const char *delimiter, const char *outfile);
void	here_doc(const char *argv, t_pipex *pipex);
//------

// STRING UTILS
char	**ft_split(char const *s, char c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strdup(const char *src);
size_t ft_strlen(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
int ft_putnbr(int nb, int log);
int ft_putchr(int c, int log);
int ft_putstr(char *str, int log);
void ft_print_pipe(int pipe, int log_file);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
//-------------

// FREE UTILS
void free_cmds(t_cmd **cmds,int ncmd);
void free_pipex(t_pipex *pipex);
void close_pipes(t_pipex *pipex);
//-----------

// CHILD
void child_work(t_pipex *pipex, char **envp, int pid_n);
//-----

// DEBUG
int *create_log_files(int n_cmds);
//------

// ERROR
int msg(char *err);
void msg_error(char *err, int to_free);
void dup_handle(int tube, int pos);
void handle_waitpid(pid_t pid);
//-----

#endif