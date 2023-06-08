#include "Minitalk.h"
#include "./libft/libft.h"
#include <stdio.h>

char *binarystring;
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
char btoa(char *src)
{
	int	a;
	int i;

	i = 0;
	a = 0;
	if (checkfornullbyte(src))
		return('\0');
	while (src[i])
	{
			a = (a * 2) + (src[i] - '0');
		 	i++;
	}
	return(a);
}

void recievebinarystring(int sig)
{
	char *binaryvalue;

	binaryvalue = ft_calloc(2, sizeof(char));
	if (sig == SIGUSR1)
		binaryvalue[0] = '1';
	if (sig == SIGUSR2)
		binaryvalue[0] = '0';
	binarystring = ft_strjoin(binarystring,binaryvalue); // set this func to return a char and not use a global var 
	free(binaryvalue);
	if (ft_strlen(binarystring) == 8)
	{
		if (btoa(binarystring) == '\0')
			printf("\n");
		else
			printf("%c",btoa(binarystring));
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
//signal verification
