/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:58:05 by jfoltan           #+#    #+#             */
/*   Updated: 2023/06/12 19:26:47 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

char *g_binaryvalue;

int checkfornullbyte(char *str)
{
	int i;
	int zeros;

	zeros = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			zeros++;
		else
			zeros = 0;
		i++;
	}
	if (zeros == 8)
		return (1);
	else
		return (0);
}

char btoa(char *src)
{
	int a;
	int i;

	i = 0;
	a = 0;
	if (checkfornullbyte(src))
		return ('\0');
	while (src[i])
	{
		a = (a * 2) + (src[i] - '0');
		i++;
	}
	return (a);
}

int recievebinarystring(int sig)
{
	static int i = 0;

	if (sig == SIGUSR1)
	{
		g_binaryvalue[i] = '1';
		i++;
	}
	if (sig == SIGUSR2)
	{
		g_binaryvalue[i] = '0';
		i++;
	}
	if (i == 8)
	{
		if (btoa(g_binaryvalue) == '\0')
		{
			ft_putchar_fd('\n', 1);
			g_binaryvalue[0] = '\0';
			i = 0;
			return (0);
		}
		else
			ft_putchar_fd(btoa(g_binaryvalue), 1);
		g_binaryvalue[0] = '\0';
		i = 0;
	}
	return (1);
}

void action(int sig, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (recievebinarystring(sig) == 1)
		{
			usleep(150);
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_putstr_fd("\n\nTransmission failed!\n\n", 1);
		}
		else
		{
			kill(info->si_pid, SIGUSR2);
			ft_putstr_fd("\n\nMessage recieved succesfully!\n\n", 1);
		}
	}
	if (sig == SIGINT)
	{
		free(g_binaryvalue);
		exit(1);
	}
}

int main(void)
{
	int pid;
	struct sigaction act;

	g_binaryvalue = ft_calloc(9, sizeof(char));
	pid = getpid();
	ft_putstr_fd("Server's PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	act.sa_sigaction = &action;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
	}
}
