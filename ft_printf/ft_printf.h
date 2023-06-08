/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:33:48 by jfoltan           #+#    #+#             */
/*   Updated: 2023/03/07 12:47:17 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

int Minatoldmetomakeaseparatefunctiontoprintapercentsignlol();
int	ft_printnbr(int n);
int ft_printchar(int c);
int ft_printstr(char *str);
int ft_num_lenght(long f);
char *ft_uitoa(unsigned int n);
int	ft_print_unsigned(unsigned int n);
char *strreverse(char *str);
int ft_hexconvert(long d,char c);
int ft_ptrgod(unsigned long long ptr);
int		ft_printf(const char *lststring, ...);
size_t	ft_strlen(const char *s);
#endif