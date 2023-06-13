#include "../include/pipex.h"

int *create_log_files(int n_cmds)
{
  int i;
  int *fds;
  char *file_name;
  char *int_to_s;
  char *error;

  i = -1;
  fds = (int *)malloc(sizeof(int) * n_cmds);
  while (++i < n_cmds)
  {
    int_to_s = ft_itoa(i);
    file_name = ft_strjoin("./debug/log_file_", int_to_s);
    if (!file_name)
      msg_error("error creating file_name", 1);
    fds[i] = open(file_name, O_CREAT | O_RDWR | O_APPEND, 0644);
    free(int_to_s);
    if (fds[i] == -1)
    {
      error = ft_strjoin("error opening/creating log file ", file_name);
      free(file_name);
      msg_error(error, 1);
    }
    free(file_name);
  }
  return (fds);
}
