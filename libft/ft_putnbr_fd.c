/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:11:10 by jfoltan           #+#    #+#             */
/*   Updated: 2023/07/14 21:00:57 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	t;

	t = n;
	if (t == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (t < 0)
		{
			ft_putchar_fd('-', fd);
			t = t * -1;
		}
		if (t >= 10)
		{
			ft_putnbr_fd(t / 10, fd);
			ft_putchar_fd((t % 10) + 48, fd);
		}
		if (t < 10)
			ft_putchar_fd((char)(t + 48), fd);
	}
}
