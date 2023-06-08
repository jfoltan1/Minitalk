#include "ft_printf.h"

int ft_printstr(char *s)
{
   int	i;
   int numofchars;
   numofchars = 0;
   i = 0;
	while (s[i])
	{
		numofchars += write(1, &s[i], 1);
		i++;
	}
return(numofchars);
}