#include "ft_printf.h"

int ft_num_lenght(long f)
{
	int numofchars;

	numofchars = 0;
	if (f < 0)
	{
			f = f * -1;
			numofchars++;
	}
		while (f != 0)
		{
			numofchars++;
			f = f / 10;
		}
	return(numofchars);
}
char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_lenght((long)n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		print_length += ft_printstr(num);
		free(num);
	}
	return (print_length);
}