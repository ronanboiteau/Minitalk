#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "colors.h"
#include "server.h"

char		g_signal;

static void	_init_server(t_server *data)
{
  if (signal(SIGUSR1, _signal_catcher) == SIG_ERR
      || signal(SIGUSR2, _signal_catcher) == SIG_ERR)
    my_exit(EXIT_FAILURE, "ERROR: Can't initiate signal handler.\n");
  g_signal = 0;
  if ((data->buffer = malloc(sizeof(char) * (BUFF + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  data->pid_client = 0;
  data->idx_pid = 0;
  data->idx_buf = 0;
  data->idx = 0;
  my_printf("Server ready! PID: %i\n", getpid());
  return ;
}

static void	_print_buff(t_server *data)
{
  int		size;

  if (data->buffer == NULL)
    return ;
  size = 0;
  while (data->buffer[size] != EOT)
    size += 1;
  write(1, data->buffer, size);
  data->pid_client = 0;
  data->idx_pid = 0;
  data->idx_buf = 0;
  free(data->buffer);
  if ((data->buffer = malloc(sizeof(char) * (BUFF + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  return ;
}

static void	_acknowledge(int pid, int tmp)
{
  if (tmp == 0 && kill(pid, SIGUSR1) == -1)
    my_exit(EXIT_FAILURE, B_RED "\nERROR: Client lost!\n" RESET);
  return ;
}

static void	_get_client_pid(t_server *data, int sig)
{
  data->pid_client = data->pid_client << 1;
  if (_get_packet(&sig, &data->idx_pid) == 1)
    data->pid_client += 1;
  return ;
}

int		main(void)
{
  t_server	data;
  int		tmp;

  _init_server(&data);
  while (true)
    {
      tmp = _wait_for_signal();
      if (data.idx_pid < 23)
	_get_client_pid(&data, tmp);
      else
	{
	  data.bin[data.idx] = _get_packet(&tmp, &data.idx);
 	  if (data.idx == 8)
	    {
	      if ((data.buffer[data.idx_buf] = _get_char(&data)) == EOT
		  && (tmp = 1))
		_print_buff(&data);
	      else
		data.idx_buf += 1;
	      data.buffer = _update_buf(data.buffer, data.idx_buf);
	    }
	  _acknowledge(data.pid_client, tmp);
	}
    }
  return (EXIT_SUCCESS);
}
