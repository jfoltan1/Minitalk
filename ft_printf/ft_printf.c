#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_format(va_list args, const char format)
{
    int numofchars;

	numofchars = 0;
    if (format == 'c')
		numofchars += ft_printchar(va_arg(args, int));
	else if (format == 's')
		numofchars += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		numofchars += ft_ptrgod(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		numofchars += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		numofchars += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		numofchars += ft_hexconvert(va_arg(args, unsigned int), format);
	else if (format == '%')
		numofchars += Minatoldmetomakeaseparatefunctiontoprintapercentsignlol();
	return (numofchars);
}
int ft_printf(const char *str, ...)
{
  int		i;
	va_list	args;
	int	numofchars;

	i = 0;
	numofchars = 0;
	va_start(args, str);
	while (str[i])
    {
        if (str[i] == '%')
        {
            numofchars += ft_format(args,str[i + 1]);
            i++;
        }
    
        else
			numofchars += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (numofchars);
}