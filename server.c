#include "minitalk.h"

void	action(int sig, siginfo_t *info, void *context)
{
	if (signal == SIGUSR1)
		printf("1");
	if (signal == SIGUSR2)
		printf("0");
}
int main(void)
{
	int	pid;
	struct sigaction	act;

	pid = getpid ();
	printf ("Server's PID: %d \n",pid);

	act.sa_sigaction = action;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	while (1)
	{
		pause();
	}

}
