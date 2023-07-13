/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:48:55 by jfoltan           #+#    #+#             */
/*   Updated: 2022/12/19 10:48:56 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	ft_checklenght(char const *s, unsigned int start, size_t len)
{
	if (ft_strlen(s) < len + start)
		return ((ft_strlen(s) - start));
	else
		return (len);
}

static char	*ft_nullmeup(void)
{
	char	*str;

	str = malloc(sizeof(char));
	if (str == 0)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*ptr;

	len = ft_checklenght(s, start, len);
	if (ft_strlen(s) < start)
		return (ft_nullmeup());
	i = 0;
	j = 0;
	ptr = (char *)malloc((len + 1) * sizeof(*s));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}
