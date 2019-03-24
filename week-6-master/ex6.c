#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


int main() {

    pid pid1;
    int fd[2];
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe error\n");
        return 1;
    }

    pid1 = fork();

    if (pid1 < 0) {
        fprintf(stderr, "Fork1 error\n");
        return 1;
    }
    else if (pid1 > 0) { // parent process
        printf("Parent1 %d \n", getpid());

        pid pid2;
        pid2 = fork();

        if (pid2 < 0) {
            fprintf(stderr, "Fork2 error\n");
            return 1;
        }
        else if (pid2 == 0) { // child#2 process
            printf("Child2  %d  created by parent %d \n", getpid(), getppid());

            while (1) {
                printf("Child2: I'm alive!\n");
                sleep(1);
            }

            exit(0);
        }
        else {
            close(fd[0]);
            write(fd[1], &pid2, sizeof(pid2));
            close(fd[1]);
            int status;
            printf("Parent %d is waiting for child2 %d \n", getpid(), pid2);
            waitpid(pid2, &status, 0);
            printf("Child2 status is %d\n", status);
            return 0;
        }
    }
    else {
        printf("Child1 %d was created by parent  %d \n", getpid(), getppid());
        pid pid2;
        close(fd[1]);
        read(fd[0], &pid2, sizeof(pid2));
        close(fd[0]);
        printf("Child2 pid is with Child1 :  %d \n", pid2);
        sleep(2);
        printf(" Child1 sending signal \n");
        kill(pid2, SIGSTOP);
        exit(0);
    }
}
