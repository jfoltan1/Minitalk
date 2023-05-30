#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

char *atob(char ascii)
{
	int	i;
	int	a;
	int b;
	char *binary;
	binary = (char*)malloc(sizeof(char) * 9);
	if (!binary)
		return(NULL);
	b = 0;
	i = 1;
	a = (int)ascii;
	while(a != 0)
	{
		i = a % 2;
		a = a / 2;
		binary[b] = i + 48;
		b++;
	}
	binary[8] = '\0';
	return (ft_strreverse(binary));
}

char btoa(char *src)
{
	int	a;
	int i;

	i = 0;
	a = 0;
	while (src[i])
	{
		a = (a * 2) + (src[i] - '0');
		 i++;
	}
	return((char)a);
}
int	main(void)
{
	char *binary = "1001100";
	printf("%c\n",btoa(binary));
}
