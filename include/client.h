/*
** client.h for minitalk in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Mon Feb  1 00:34:19 2016 Ronan Boiteau
** Last update Sun Feb 21 00:39:50 2016 Ronan Boiteau
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <sys/types.h>

void		_send_letter(char letter, pid_t pid_server);
void		_send_pid(pid_t pid_client, pid_t pid_server);

extern int	g_acknowledge;

#endif /* !CLIENT_H_ */
