#include <signal.h>

char		_get_packet(int *tmp, int *idx)
{
  char		data;

  if (*tmp == SIGUSR1)
    data = 0;
  else
    data = 1;
  *idx += 1;
  *tmp = 0;
  return (data);
}
