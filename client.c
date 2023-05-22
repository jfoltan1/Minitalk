#include "minitalk.h"

int main (int argc, char **argv)
{
	int spid;

	spid = ft_atoi(argv[1]);
	kill(spid, SIGINT);
}
