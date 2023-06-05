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
  int j;

  i = -1;
  while (cmds[++i])
  {
    j = -1;
    free(cmds[i]->cmd);
    while (cmds[i]->f_cmd[++j])
      free(cmds[i]->f_cmd[j]);
    free(cmds[i]->f_cmd);
  }
}

void free_pipex(t_pipex *pipex)
{
  int i;
  int j;
  i = 0;

  free(pipex->cmd_paths);
  free(pipex->cmds);
  // while (pipex->cmd_paths[i])
  //   free(pipex->cmd_paths[i]);
  i = -1;
  // while (pipex->cmds[++i])
  // {
  // j = -1;
  //   free(pipex->cmds[i]->cmd);
  // while (pipex->cmds[i]->f_cmd[++j])
  // free(pipex->cmds);
  // free(pipex->cmds);
  // }

  free(pipex->pids);
  // free(pipex->cmds);
  // free(pipex->cmd_paths);
  close(pipex->infile);
  close(pipex->outfile);
  close_log_files(pipex);
}
void close_pipes(t_pipex *pipex)
{
  int i;

  i = -1;
  while (++i < (pipex->n_pipes))
    close(pipex->tube[i]);
}