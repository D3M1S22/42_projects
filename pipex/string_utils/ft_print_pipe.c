#include "../include/pipex.h"

void ft_print_pipe(int pipe, int log_file)
{
  char *buffer;
  int byte_r;
  int i;

  i = 0;
  buffer = malloc(sizeof(char *) * 10000000);
  if (!buffer)
    msg_error("Errore buffer\n");
  byte_r = read(pipe, &buffer[i++], 255);
  while (byte_r > 0)
    byte_r = read(pipe, &buffer[i++], 255);
  ft_putstr(buffer, log_file);
  free(buffer);
}