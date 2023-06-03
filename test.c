	#include "Minitalk.h"
	#include <stdio.h>
	#include "./libft/libft.h"
	char *ft_strreverse(char *src)
{
    int i;
    char *output;
    int a;

    a = 0;
    i = ft_strlen(src);
    output = (char *)malloc(sizeof(char) * (i + 1));
    if (!output)
        return (NULL);

    while (i > 0)
    {
        i--;
        output[a] = src[i];
        a++;
    }
    output[a] = '\0';

    return output;
}
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
char *atob(char ascii)
{
	int	i;
	int	a;
	int b;
	char *binary;
	binary = (char*)malloc(sizeof(char) * 8);
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
	while (b <= 7)
	{
		binary[b] = '0';
		b++;
	}
	binary[8] = '\0';
	return (ft_strreverse(binary));
}
int main(void)
{
	char *binary = "010010000110010101101100011011000110111100100000011010000110111101110111001000000110000101110010011001010010000001111001011011110111010100111111";
	int i;
	i = 0;
	//while(1)
	//{
		printf("%s",btoa(binary));
		//i++;
		//if (binary[i] == '\0')
		//break;
	//}
}