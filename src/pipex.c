#include "../include/pipex.h"

t_cmd **check_cmds(t_cmd **cmds, int ncmds, char *tmp, char *command)
{
  int i;

  if (tmp)
    free(tmp);
  if (command)
    free(command);
  i = -1;
  while (++i < ncmds)
  {
    if (!cmds[i]->cmd)
    {
      free_cmds(cmds);
      msg_error(ERR_CMD, 0);
    }
  }
  return (cmds);
}

t_cmd **malloc_cmds(size_t size)
{
  t_cmd **tmp;

  tmp = (t_cmd **)malloc(size);
  if (!tmp)
    msg_error("Errore allocando memoria\n", 0);
  return (tmp);
}

t_cmd **ft_parse_cmd(char **args, int ncmds, char **paths)
{
  t_cmd **cmds;
  char *tmp;
  char *command;
  int i;
  int j;

  i = -1;
  cmds = malloc_cmds(ncmds * sizeof(t_cmd *));
  while (++i < ncmds && args[i])
  {
    cmds[i] = malloc(sizeof(t_cmd));
    cmds[i]->f_cmd = ft_split(args[i], ' ');
    j = -1;
    while (paths[++j])
    {
      tmp = ft_strjoin(paths[j], "/");
      command = ft_strjoin(tmp, cmds[i]->f_cmd[0]);
      cmds[i]->cmd = ft_strdup(command);
      if (access(cmds[i]->cmd, 0) == 0)
        break;
      free(tmp);
      free(command);
    }
  }
  return (check_cmds(cmds, ncmds, tmp, command));
}

char **ft_parse_paths(char **envp)
{
  while (ft_strncmp("PATH", *envp, 4))
    envp++;
  return ft_split(*envp, ':');
}

void pipex(t_pipex *pipex, const char **argv, char **envp)
{
  int i;

  pipex->cmd_paths = ft_parse_paths(envp);
  pipex->cmds = ft_parse_cmd(((char **)argv) + 2, pipex->n_cmds, pipex->cmd_paths);
  pipex->tube = (int *)malloc(sizeof(int) * (pipex->n_pipes));
  i = -1;
  while (++i < pipex->n_cmds - 1)
    if (pipe(pipex->tube + 2 * i) == -1)
      free_pipex(pipex);
  pipex->pids = (int *)malloc(pipex->n_cmds * sizeof(int));
  i = -1;
  while (++i < pipex->n_cmds)
  {
    pipex->pids[i] = fork();
    if (pipex->pids[i] == -1)
      msg_error("pid error", 0);
    else if (!pipex->pids[i])
      child_work(pipex, envp, i);
  }
  // if (pipex->pids[i] == 0) // if (pipex->pids[i] == 0 && pipex->pids[i])
  close_pipes(pipex);
  handle_waitpid(-1);
  free_pipex(pipex);
}
