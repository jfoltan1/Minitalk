/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:57:03 by jfoltan           #+#    #+#             */
/*   Updated: 2023/07/14 20:59:37 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreverse(char *src)
{
	int		i;
	char	*output;
	int		a;

	a = 0;
	i = ft_strlen (src);
	output = malloc(sizeof (char) * (i + 1));
	if (!output)
		return (NULL);
	while (i > 0)
	{
		i--;
		output[a] = src[i];
		a++;
	}
	output[a] = '\0';
	free(src);
	return (output);
}
