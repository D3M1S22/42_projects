#include "include/pipex.h"

int main(int argc, char const **argv, char **const envp)
{
  int f1;
  int f2;
  t_pipex *pipex_s;
  if (argc < 5)
  {
    printf("Not enough arguments\nGot: %d, Expected: %d+\n", argc, 5);
    return (0);
  }
  f1 = open(argv[1], O_RDONLY);
  f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0000644);
  if (f1 == -1)
    return (printf("%s %s\n", strerror(errno), argv[1]));
  if (f2 == -1)
    return (printf("%s %s\n", strerror(errno), argv[argc - 1]));
  pipex_s = (t_pipex *)malloc(sizeof(t_pipex));
  pipex_s->infile = f1;
  pipex_s->outfile = f2;
  pipex_s->n_cmds = argc - 3;
  pipex_s->n_pipes = 2 * (pipex_s->n_cmds - 1);
  pipex_s->log_files = create_log_files(argc - 3);
  // create_log();
  // pipex_s.log_file = open("log.txt", O_CREAT | O_RDWR | O_APPEND, 0644);
  pipex(pipex_s, argv, envp); // argc - 3
}
