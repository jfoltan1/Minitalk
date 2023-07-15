/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:50:24 by jfoltan           #+#    #+#             */
/*   Updated: 2022/12/19 10:50:25 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ptr;

	i = ft_strlen(s) + 1;
	ptr = (char *) malloc(sizeof(char) * i);
	if (!ptr)
		return (NULL);
	ptr = ft_memcpy(ptr, s, i);
	return (ptr);
}
