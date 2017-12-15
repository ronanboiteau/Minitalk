#include <signal.h>
#include <unistd.h>
#include "my.h"
#include "server.h"

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
