#include "../include/pipex.h"

void read_pipes(int pipe, int file)
{
  char buffer[4096];
  ssize_t bytes_read = 1;
  while (bytes_read > 0)
  {
    bytes_read = read(pipe, buffer, sizeof(buffer));
    if (bytes_read == -1)
      msg_error("error reading", 0);
    if (write(file, buffer, bytes_read) != bytes_read)
      msg_error("error writing", 0);
  }
}

static void sub_dup2(int zero, int first)
{
  dup2(zero, 0);
  dup2(first, 1);
}

void child_work(t_pipex *pipex, char **envp, int pid_n)
{
  if (pid_n == 0)
    sub_dup2(pipex->infile, pipex->tube[1]);
  else if (pid_n == pipex->n_cmds - 1)
    sub_dup2(pipex->tube[2 * pid_n - 2], pipex->outfile);
  else
    sub_dup2(pipex->tube[2 * pid_n - 2], pipex->tube[2 * pid_n + 1]);
  close_pipes(pipex);
  execve(pipex->cmds[pid_n]->cmd, pipex->cmds[pid_n]->f_cmd, envp);
}
