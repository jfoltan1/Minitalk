/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:10:14 by jfoltan           #+#    #+#             */
/*   Updated: 2023/07/14 16:17:58 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"
char		*g_string_to_send;
char	*atob(char ascii)
{
	int		i;
	int		a;
	int		b;
	char	*binary;

	binary = malloc(9 * sizeof(char));
	if (!binary)
		return (NULL);
	b = 0;
	i = 1;
	a = (int)ascii;
	while (a != 0)
	{
		i = a % 2;
		a = a / 2;
		binary[b] = '0' + i;
		b++;
	}
	while (b < 8)
	{
		binary[b] = '0';
		b++;
	}
	binary[b] = '\0';
	return (ft_strreverse(binary));
}

void	error_check(int argc, int spid)
{
	if (argc != 3 || (spid <= 4500))
	{
		ft_putstr_fd("Invalid input!", 2);
		exit(2);
	}
}

void	send_null(int spid)
{
	int	a;

	a = 0;
	while (a < 8)
	{
		kill(spid, SIGUSR2);
		pause();
		a++;
	}
}

void	action_client(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	static int i = 0;


	i = 0;
	if (sig == SIGUSR1)
		i++;
	if (sig == SIGINT || sig == SIGUSR2)
	{
		free(g_string_to_send);
		exit(0);
	}
}
int	main(int argc, char **argv)
{
	int		spid;
	struct sigaction act;
	int	i;
	char	*binary;

	error_check(argc,ft_atoi(argv[1]));
	i = 0;
	g_string_to_send = ft_calloc(8, sizeof(char));
	spid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		binary = atob(argv[2][i]);	
		g_string_to_send = ft_strjoin(g_string_to_send,binary);
		i++;	
	}
	i = 0;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = &action_client;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (g_string_to_send[i])
	{
		if (g_string_to_send[i] == '1')
			if (kill(spid,SIGUSR1) == -1)
				ft_putstr_fd("\n\nTransmission failed!", 1);
		if (g_string_to_send[i] == '0')
			if (kill(spid,SIGUSR2) == -1)
				ft_putstr_fd("\n\nTransmission failed!", 1);
		pause();
		i++;
	}
	send_null(spid);
}
