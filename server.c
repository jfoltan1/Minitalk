#include "Minitalk.h"
	char btoa(char *src)
{
	int	a;
	int i;

	i = 0;
	a = 0;
	while (src[i])
	{
		a = (a * 2) + (src[i] - '0');
		 i++;
	}
	return((char)a);
}
void action(int sig, siginfo_t *info, void *context)
{
    (void)context;
	(void)info;
	//char	*ascii;
	//int		i;

	/*ascii = calloc(8, sizeof(char));
	i = 0;
	while (i < 8)
	{
		if (sig == SIGUSR1)
       		ascii[i] = '1';
    	if (sig == SIGUSR2)
        	ascii[i] = '0';
	i++;
	}*/
	//printf("%c",btoa(ascii));
	if (sig == SIGUSR1)
       		printf("1");
    if (sig == SIGUSR2)
        	printf("0");
    fflush(stdout);
}

int main(void)
{
    int pid;
    struct sigaction act;

    pid = getpid();
    printf("Server's PID: %d\n", pid);
    act.sa_sigaction = action;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);

    while (1)
    {    
		pause();
	}
}
