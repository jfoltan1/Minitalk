#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
pid_t	get_pid(void)
{
	pid_t	pid_server;

	pid_server = getpid();
	return(pid_server);
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
