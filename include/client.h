#ifndef CLIENT_H_
# define CLIENT_H_

# include <sys/types.h>

# define EOT (4)

extern int	g_acknowledge;

void		_send_letter(char letter, pid_t pid_server);
void		_send_pid(pid_t pid_client, pid_t pid_server);

#endif /* !CLIENT_H_ */
