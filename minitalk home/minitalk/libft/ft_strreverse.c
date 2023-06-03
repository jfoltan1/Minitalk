#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
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