/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:10:14 by jfoltan           #+#    #+#             */
/*   Updated: 2023/07/14 20:40:32 by jfoltan          ###   ########.fr       */
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
	static int	i = 0;

	(void) context;
	(void) info;
	i = 0;
	if (sig == SIGUSR1)
		i++;
	if (sig == SIGINT || sig == SIGUSR2)
	{
		free (g_string_to_send);
		exit (0);
	}
}

void	send_binary(int spid, char *str)
{
	int		i;
	char	*binary;

	i = 0;
	while (str[i])
	{
		binary = atob(str[i]);
		g_string_to_send = ft_strjoin(g_string_to_send, binary);
		i++;
	}
	i = 0;
	while (g_string_to_send[i])
	{
		if (g_string_to_send[i] == '1')
			if (kill(spid, SIGUSR1) == -1)
				ft_putstr_fd("\n\nTransmission failed!", 1);
		if (g_string_to_send[i] == '0')
			if (kill(spid, SIGUSR2) == -1)
				ft_putstr_fd("\n\nTransmission failed!", 1);
		pause();
		i++;
	}
	send_null(spid);
}

int	main(int argc, char **argv)
{
	int					spid;
	struct sigaction	act;

	if (argc != 3)
	{
		ft_putstr_fd("Invalid input!", 2);
		exit(2);
	}
	spid = ft_atoi(argv[1]);
	if (spid <= 1000)
	{
		ft_putstr_fd("This pid is reserved for the system!", 2);
		exit(2);
	}
	else
	{
		g_string_to_send = ft_calloc(8, sizeof(char));
		sigemptyset(&act.sa_mask);
		act.sa_sigaction = &action_client;
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGINT, &act, NULL);
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		send_binary(spid, argv[2]);
	}
}
