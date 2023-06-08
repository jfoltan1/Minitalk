#include "ft_printf.h"

int ft_printnbr(int n)
{
	int len;
	char *num;

	len = 0;
	num = ft_uitoa(n);
	len = ft_printstr(num);
	free(num);
	return(len);
}