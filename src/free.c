#include "../include/pipex.h"

void close_log_files(t_pipex *pipex)
{
  int i;

  i = -1;
  while (++i < pipex->n_cmds)
    close(pipex->log_files[i]);
}

void free_cmds(t_cmd **cmds)
{
  int i;

  i = -1;
  while (cmds[++i])
  {
    free(cmds[i]->f_cmd);
    free(cmds[i]->cmd);
  }
  free(cmds);
}

void free_pipex(t_pipex *pipex)
{
  // int i;

  // i = -1;
  // free(pipex->cmd_paths);
  // // free(pipex->cmds);
  // while (pipex->cmds[++i])
  // {
  //   free(pipex->cmds[i]->f_cmd);
  //   free(pipex->cmds[i]->cmd);
  // }
  // free(pipex->cmds);
  // free(pipex->tube);
  // free(pipex->pids);
  // free(pipex->cmds);
  // close(pipex->infile);
  // close(pipex->outfile);
  // close_log_files(pipex);
  // free(pipex->log_files);
  // free(pipex);
  exit(0);
}
void close_pipes(t_pipex *pipex)
{
  int i;

  i = -1;
  while (++i < (pipex->n_pipes))
    close(pipex->tube[i]);
}