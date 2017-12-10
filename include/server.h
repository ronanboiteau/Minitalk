/*
** server.h for minitalk in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Feb  1 01:25:43 2016 Ronan Boiteau
** Last update Sat Feb 20 21:26:38 2016 Ronan Boiteau
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <sys/types.h>

# define BUFF (320)

typedef struct	s_server
{
  pid_t		pid_client;
  int		idx_pid;
  char		bin[7];
  char		*buffer;
  int		idx_buf;
  int		idx;
}		t_server;

char		_get_char(t_server *data);
char		_get_packet(int *tmp, int *idx);
pid_t		_get_pid_decimal(char *pid_bin);
char		*my_realloc(char *str, t_uint new_size);
void		_signal_catcher(int signal);
char		*_update_buf(char *buffer, int idx_buf);
char		_wait_for_signal(void);

extern char	g_signal;

#endif /* !SERVER_H_ */
