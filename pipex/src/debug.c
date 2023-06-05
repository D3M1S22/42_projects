#include "../include/pipex.h"

int *create_log_files(int n_cmds)
{
  int i;
  int *fds;
  char *file_name;

  i = -1;
  fds = (int *)malloc(sizeof(int) * n_cmds);
  while (++i < n_cmds)
  {
    file_name = ft_strjoin("./debug/log_file_", ft_int_to_str(i));
    if (!file_name)
      msg_error("error creating file_name");
    fds[i] = open(file_name, O_CREAT | O_RDWR | O_APPEND, 0644);
    if (fds[i] == -1)
      msg_error(ft_strjoin("error opening/creating log file ", file_name));
  }
  free(file_name);
  return (fds);
}