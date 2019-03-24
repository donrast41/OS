#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


void signal_handler(int);

void signal_handler(int sig_num) {
    printf("Caught %d", sig_num);
    if (sig_num == SIGKILL) {
        printf(" - SIGKILL\n");
    }
    else if (sig_num == SIGUSR1) {
        printf(" - SIGUSR1\n");
    }
    else if (sig_num == SIGSTOP) {
        printf(" - SIGSTOP\n");
    }
    exit(0);
}

int main() {
    signal(SIGKILL, signal_handler);
    signal(SIGSTOP, signal_handler);
    signal(SIGUSR1, signal_handler);

    while (1) {
        sleep(1);
    }

    return 0;
}

