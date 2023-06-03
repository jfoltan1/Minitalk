#include "Minitalk.h"
char *binarystring;
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
int	checkfornullbyte(char *str)
{
	int i = ft_strlen(str) - 1;
    int zeros = 0;

    while (i >= 0 && zeros < 8)
    {
        if (str[i] == '0')
            zeros++;
        else
            zeros = 0;

        i--;
    }

    if (zeros == 8)
        return 1;
    else
        return 0;
}

void recievebinarystring(int sig)
{
	char *binaryvalue;

	binaryvalue = ft_calloc(2, sizeof(char));
	if (sig == SIGUSR1)
		binaryvalue[0] = '1';
	if (sig == SIGUSR2)
		binaryvalue[0] = '0';
	binarystring = ft_strjoin(binarystring,binaryvalue);
	if (checkfornullbyte(binarystring))
	{
		printf("%s",binarystring);
		fflush(stdout);
	}
	fflush(stdout);
}
void action(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;

	if (sig == SIGUSR1 || sig == SIGUSR2)
		recievebinarystring(sig);
}

int main(void)
{
	int pid;
    struct sigaction act;

	binarystring = ft_calloc(2, sizeof(char));
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
