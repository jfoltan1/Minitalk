#include "ft_printf.h"
int ft_ptrgod(unsigned long long ptr)
{
    int numofchars;
	numofchars = 0;
	char identity;
    identity = 'x';
    numofchars += write(1, "0x", 2);

	numofchars += ft_hexconvert((unsigned long)ptr, identity);
	return(numofchars);
}