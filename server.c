#include "Minitalk.h"
char *binarystring;
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
		ft_printf("%s\n",btoa(binarystring));
		// fflush(stdout);
		binarystring[0] = '\0';
	}
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
    ft_printf("Server's PID: %d\n", pid);
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
//signal verification
