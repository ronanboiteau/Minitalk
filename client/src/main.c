#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "client.h"
#include "my.h"

int		g_acknowledge;

static void	_signal_catcher(int signal)
{
  if (signal == SIGUSR1)
    g_acknowledge = true;
  return ;
}

static char	_chk_str(char *str)
{
  int		idx;

  idx = 0;
  while (str[idx])
    {
      if (str[idx] == EOT)
	return (EXIT_FAILURE);
      idx++;
    }
  return (EXIT_SUCCESS);
}

static void	_chk_args(int argc, char **argv)
{
  if (argc != 3)
    my_exit(EXIT_FAILURE, "Usage: %s [SERVER PID] [MSG]\n", argv[0]);
  if (my_str_isnum(argv[1]) == false)
    my_exit(EXIT_FAILURE, "ERROR: PID must contain digits only!\n");
  if (my_atoi(argv[1]) <= 0)
    my_exit(EXIT_FAILURE, "ERROR: Invalid server PID.\n");
  if (_chk_str(argv[2]) == EXIT_FAILURE)
    my_exit(EXIT_FAILURE, "ERROR: Your message can't contain EOT(s)!\n");
  return ;
}

int		main(int argc, char **argv)
{
  pid_t		pid_server;
  pid_t		pid_client;
  int		idx;

  g_acknowledge = false;
  _chk_args(argc, argv);
  if (signal(SIGUSR1, _signal_catcher) == SIG_ERR
      || signal(SIGUSR2, _signal_catcher) == SIG_ERR)
    my_exit(EXIT_FAILURE, "ERROR: Can't initiate signal handler.\n");
  pid_client = getpid();
  pid_server = my_atoi(argv[1]);
  _send_pid(pid_client, pid_server);
  idx = 0;
  while (idx < my_strlen(argv[2]))
    {
      _send_letter(argv[2][idx], pid_server);
      idx += 1;
    }
  _send_letter(EOT, pid_server);
  usleep(100);
  my_printf("Successfully sent message to %i!\n", pid_server);
  return (EXIT_SUCCESS);
}
