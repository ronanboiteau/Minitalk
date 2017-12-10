/*
** letter.c for minitalk in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Feb  1 01:27:44 2016 Ronan Boiteau
** Last update Sat Feb 20 21:26:22 2016 Ronan Boiteau
*/

#include "my.h"
#include "colors.h"
#include "server.h"
#include <signal.h>
#include <stdlib.h>

char		_get_char(t_server *data)
{
  char		letter;
  int		idx_bin;

  data->idx = 0;
  idx_bin = 0;
  letter = 0;
  while (idx_bin < 8)
    {
      letter = letter << 1;
      if (data->bin[idx_bin] == 1)
	letter += 1;
      idx_bin += 1;
    }
  return (letter);
}

char		*_update_buf(char *buffer, int idx_buf)
{
  buffer[idx_buf] = C_NUL;
  if (idx_buf % BUFF == 0)
    buffer = my_realloc(buffer, BUFF * ((idx_buf / BUFF) + 1));
  return (buffer);
}
