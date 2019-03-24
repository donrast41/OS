#include <stdio.h>
#include <unistd.h>

char* str_word = "ezio auditore da firenze";
char str_empty [100];

int main(){
    int fd[2];
    pipe(fd);

    int pid = fork();
    if (pid>0){
        write(fd[1], str_word, 100);
        close(fd[1]);

    } else
        if (pid==0){
        read(fd[0], str_empty, 100);
        printf("String formed :%s\n", str_empty);
        close(pi[0]);

    }

    close(fd[0]);
}
