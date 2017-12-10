/*
** get_packet.c for minitalk in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Feb  1 01:25:03 2016 Ronan Boiteau
** Last update Sat Feb 20 19:57:01 2016 Ronan Boiteau
*/

#include <signal.h>

char		_get_packet(int *tmp, int *idx)
{
  char		data;

  if (*tmp == SIGUSR1)
    data = 0;
  else if (*tmp == SIGUSR2)
    data = 1;
  *idx += 1;
  *tmp = 0;
  return (data);
}
