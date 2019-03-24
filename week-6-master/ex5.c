#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int sig_num) {
	switch (sig_num) {
		case SIGINT:
			printf("\n Over.\n");
			exit(1);
	}
}

int main() {
	signal(SIGINT, signal_handler);

	pid child_pid = fork();
	if (child_pid) {
		sleep(10);
		kill(child_pid, SIGINT);
	} else {
		while (1) {
			printf("I'm alive!\n");
			sleep(1);
		}
	}

	return 0;
}
