#include <stdlib.h>
#include <unistd.h>

#include "q.h"

int main()
{
	pid_t pid;
	switch(pid = fork())
	{
		case 0:
			serve();
			break;
		case -1:
			warn ("fork to start werver failed");
			break;
		default:
			printf("server process pid is %d\n", pid);
	}
	exit(pid != -1 ? 0 : 1);
}
