	#include <stdio.h>
	#include "./libft/libft.h"
	char *btoa(char *src)
{
	int	a;
	int i;
	int b;
	int c;
	char *ascii;

	i = 0;
	b = (ft_strlen(src) / 8);
	ascii = ft_calloc(b + 1, sizeof(char));
	b = 0;
	c = 0;
	while (src[i])
	{
		while (c < 8)
		{
			a = (a * 2) + (src[i] - '0');
		 	i++;
			c++;
		}
		ascii[b] = (char)a;
		b++;
		c = 0;
	}
	ascii[b] = '\0';
	return(ascii);
}

int main(void)
{
	char *binary = "0100100001100101011011000110110001101111";
	printf("%s",btoa(binary));
	
}