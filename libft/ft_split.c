/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:44:02 by jfoltan           #+#    #+#             */
/*   Updated: 2023/07/14 20:59:58 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_delicount(char const *s, char c)
{
	int	switcharoony;
	int	a;

	switcharoony = 0;
	a = 0;
	while (*s)
	{
		if (*s != c && switcharoony == 0)
		{
			switcharoony = 1;
			a++;
		}
		else if (*s == c)
			switcharoony = 0;
		s++;
	}
	return (a);
}

static int	ft_sizecount(char const *s, char c, int i)
{
	int	d;

	d = 0;
	while (s[i] != c && s[i])
	{
		i++;
		d++;
	}
	return (d);
}

static void	ft_freemebaby(char **ptr, int f)
{
	while (f > -1)
	{
		free(ptr[f]);
		f--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		a;
	int		f;
	char	**ptr;

	i = 0;
	f = -1;
	a = ft_delicount(s, c);
	ptr = (char **)malloc((a + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (++f < a)
	{
		while (s[i] == c)
			i++;
		ptr[f] = ft_substr(s, i, ft_sizecount(s, c, i));
		if (!ptr[f])
		{
			ft_freemebaby(ptr, f);
			return (NULL);
		}
		i = ft_sizecount(s, c, i) + i;
	}
	ptr[f] = NULL;
	return (ptr);
}
