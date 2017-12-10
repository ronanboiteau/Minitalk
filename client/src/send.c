/*
** send.c for client in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Feb 11 23:38:06 2016 Ronan Boiteau
** Last update Sun Feb 21 00:40:20 2016 Ronan Boiteau
*/

#include "client.h"
#include "my.h"
#include <limits.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static void	_wait_for_acknowledge(pid_t pid_server, char signal_to_send)
{
  int		sleep_time;
  int		max_sleep;

  sleep_time = 0;
  max_sleep = 10;
  while (g_acknowledge != TRUE)
    {
      if (max_sleep > 1000)
	my_exit(EXIT_FAILURE, "ERROR: Timeout!" EOL);
      else if (sleep_time > max_sleep)
	{
	  max_sleep += 10;
	  if (kill(pid_server, signal_to_send) == -1)
	    my_exit(EXIT_FAILURE, "ERROR: Can't send data to server." EOL);
	}
      else
	usleep(200);
      sleep_time += 1;
    }
  return ;
}

void		_send_letter(char letter, pid_t pid_server)
{
  char		signal_to_send;
  int		idx_bit;

  idx_bit = 7;
  while (idx_bit >= 0)
    {
      if (((letter >> idx_bit) & 1) == 0)
	signal_to_send = SIGUSR1;
      else
	signal_to_send = SIGUSR2;
      if (kill(pid_server, signal_to_send) == -1)
	my_exit(EXIT_FAILURE, "ERROR: Invalid server PID." EOL);
      if ((letter != EOT || idx_bit != 0) && g_acknowledge != TRUE)
	_wait_for_acknowledge(pid_server, signal_to_send);
      g_acknowledge = FALSE;
      idx_bit -= 1;
    }
  return ;
}

void		_send_pid(pid_t pid_client, pid_t pid_server)
{
  int		idx;
  char		signal_to_send;

  if (pid_client > INT_MAX)
    my_exit(EXIT_FAILURE, "ERROR: PID too high! PID max: %i" EOL, INT_MAX);
  idx = 22;
  while (idx >= 0)
    {
      if (((pid_client >> idx) & 1) == 0)
	signal_to_send = SIGUSR1;
      else
	signal_to_send = SIGUSR2;
      if (kill(pid_server, signal_to_send) == -1)
	my_exit(EXIT_FAILURE, "ERROR: Invalid server PID." EOL);
      idx -= 1;
      usleep(10000);
    }
  return ;
}
