#include "Minitalk.h"
char *btoa(char *src)
{
	int	a;
	int i;
	int b;
	int c;
	char *ascii;

	i = 0;
	b = (ft_strlen(src) / 8);
	ascii = ft_calloc(b + 1, sizeof(char));
	b = 0;
	c = 0;
	while (src[i])
	{
		while (c < 8)
		{
			a = (a * 2) + (src[i] - '0');
		 	i++;
			c++;
		}
		ascii[b] = (char)a;
		b++;
		c = 0;
	}
	ascii[b] = '\0';
	return(ascii);
}
/* have to implement an allocating function, to write everything into one string of 01s */
void	second_handler(int sig)
{
	int	a;
	int	i;
	char *ascii;

	i = 0;
	a = 0;
	while (
	
}
void first_handler(int sig, siginfo_t *info, void *context)
{
    (void)context;
	(void)info;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		second_handler(int sig);
	}
}

int main(void)
{
    int pid;
    struct sigaction act;

    pid = getpid();
    printf("Server's PID: %d\n", pid);
    act.sa_sigaction = first_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);

    while (1)
    {    
		pause();
	}
}
