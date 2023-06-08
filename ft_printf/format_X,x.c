#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*strreverse(char *str)
{
	int		d;
	int		i;
	char	a;

	i = 0;
	d = 0;
	a = '0';
	i = ft_strlen(str);
	i--;
	while (i >= d)
		{
			a = str[d];
			str[d] = str[i];
			str[i] = a;
			i--;
			d++;
		}
    return(str);
}
int ft_hexconvert(long d,char c)
{
int numofchars;
char output[16];
int e;

numofchars = 0;
char hehe[] = "0123456789abcdef";
char HEHE[] = "0123456789ABCDEF";
 e = 0;
while(d > 0 && c == 88) 
{   
    output[e]=(HEHE[d%16]);
    d = d/16;
e++;
}
while(d > 0 && c == 120) 
{   
    output[e]=(hehe[d%16]);
    d = d/16;
e++;
}
output[e] = 0;
strreverse(output);
numofchars += ft_printstr(output);
return(numofchars);
}