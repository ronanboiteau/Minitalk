/*
** signal.c for server in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Feb 11 23:58:39 2016 Ronan Boiteau
** Last update Fri Feb 19 12:41:53 2016 Ronan Boiteau
*/

#include "my.h"
#include "server.h"
#include <signal.h>
#include <unistd.h>

void		_signal_catcher(int signal)
{
  g_signal = signal;
  return ;
}

char		_wait_for_signal(void)
{
  int		sig;

  if (g_signal != SIGUSR1 && g_signal != SIGUSR2)
    pause();
  sig = g_signal;
  g_signal = 0;
  return (sig);
}
