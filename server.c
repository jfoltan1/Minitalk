#include "Minitalk.h"
pid_t	get_pid(void)
{
	pid_t	pid_server;

	pid_server = getpid();
	return (pid_server);
}
void	signal_handler(int signal)
{
	
}
void server(void)
{
	printf("%d\n",get_pid());
	pause();
}
int main(void)
{
	server();
}
