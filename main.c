#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void	handle(int sig)
{
	printf("\njksdgkjs\n");
	exit(0);
}

int main()
{
	char *s = NULL;
	signal(SIGKILL, handle);
	while (1)
	{
	}
}
