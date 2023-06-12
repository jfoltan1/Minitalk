/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:10:14 by jfoltan           #+#    #+#             */
/*   Updated: 2023/06/12 19:31:15 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

char	*ft_strreverse(char *src)
{
	int		i;
	char	*output;
	int		a;

	a = 0;
	i = ft_strlen(src);
	output = (char *)malloc(sizeof(char) * (i + 1));
	if (!output)
		return (NULL);
	while (i > 0)
	{
		i--;
		output[a] = src[i];
		a++;
	}
	output[a] = '\0';
	return (output);
}

char	*atob(char ascii)
{
	int		i;
	int		a;
	int		b;
	char	*binary;

	binary = (char *)malloc(sizeof(char) * 8);
	if (!binary)
		return (NULL);
	b = 0;
	i = 1;
	a = (int)ascii;
	while (a != 0)
	{
		i = a % 2;
		a = a / 2;
		binary[b] = i + 48;
		b++;
	}
	while (b <= 7)
	{
		binary[b] = '0';
		b++;
	}
	binary[8] = '\0';
	return (ft_strreverse(binary));
}

void	error_check(int argc)
{
	if (argc != 3)
	{
		ft_putstr_fd("Invalid input!", 1);
		exit(0);
	}
}

void	send_null(int spid)
{
	int	a;

	a = 0;
	while (a < 8)
	{
		kill(spid, SIGUSR2);
		usleep(100);
		a++;
	}
}

int	main(int argc, char **argv)
{
	int		spid;
	int		i;
	int		a;
	char	*btosend;

	error_check(argc);
	a = 0;
	i = 0;
	spid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		btosend = atob(argv[2][i]);
		while (btosend[a])
		{		
			if (btosend[a] == '1')
				kill(spid, SIGUSR1);
			if (btosend[a] == '0')
				kill(spid, SIGUSR2);
			usleep(100);
			a++;
		}
		a = 0;
		i++;
	}
	send_null(spid);
}
