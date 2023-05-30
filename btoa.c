#include "./libft.h"
/*
-recieve a signal and write it to array
 */
int *recieve_signal()
{
	int *binarystring;
	int i;

	i = ft_strlen(binarystring);
	binarystring = calloc(sizeof(int) *(i + 2)); //this wont work for first allocation, or yes maybe cause of +2?
	if (signal == SIGUSR1)
		binarystring[i + 1] = 1;
	if (signal == SIGUSR2)
		binarystring[i + 1] = 0;
	//implement a countdown for null byte and then return

}


char ft_btoa(char c)
