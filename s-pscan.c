#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

#include "scanner.h"

struct servent *service;

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		fprintf(stderr, "usage: tp1 <IP/hostname>\n");
		exit(1);
	}

	int intPort;

	printf("\033[33;1m[?]\033[0m - Running scan on : %s\n", argv[1]);

	for (intPort = 1; intPort <= 1024; intPort++)
	{
		printf("\033[33;1m[?]\033[0m - Testing port %d ...\n", intPort);
		char strPort[sizeof(int) * 5];
		sprintf(strPort, "%d", intPort);

		int r = scanner(argv, strPort);
		if (r == 0)
		{
			service = getservbyport(htons(intPort), NULL);
			if (service == NULL)
			{
				printf("\033[33;1m[+]\033[0m - Possible service name = \033[33;1mUnknow\033[0m.\n");
			}
			else
			{
				printf("\033[32;1m[+]\033[0m - Possible service name = \033[32;1m%s\033[0m\n", service->s_name);
			}
		}
	}

	printf("\033[32;1m[+]\033[0m - Scan finished.\n");
	return 0;
}
