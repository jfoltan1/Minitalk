/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:22:47 by jfoltan           #+#    #+#             */
/*   Updated: 2023/07/14 21:01:24 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isneg(long f)
{
	if (f < 0)
		return (1);
	return (0);
}

static	int	ft_len(long l)
{
	int	i;

	i = 0;
	if (ft_isneg(l))
	{
		i++;
		l = l * -1;
	}
	while (l >= 10)
	{
		l = l / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	long	f;

	f = n;
	i = ft_len(f);
	if (f < 0)
		f = f * -1;
	ptr = (char *)malloc(sizeof(char) * i + 2);
	if (!ptr)
		return (NULL);
	ptr[i + 1] = 0;
	while (i >= 0)
	{
		ptr[i--] = f % 10 + '0';
		f = f / 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
