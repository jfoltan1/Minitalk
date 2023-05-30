/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:48:41 by jfoltan           #+#    #+#             */
/*   Updated: 2022/12/01 15:48:42 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	if (little[a] == '\0')
		return (((char *)big));
	if (big[i] == '\0')
		return (NULL);
	while (big[i] && i < len)
	{
		a = 0;
		while (big[i + a] && i + a < len && little[a] == big[i + a])
		{
			a++;
			if (little[a] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
