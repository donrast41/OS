#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>

/*shell script
    for(n=0;n<10;n++);
    do
        gcc main.c -o ex1
        ./ex1
        rm ex1
    done
*/

int main(){
int n=40;
pid_t pid;

switch(pid=fork()){
    case -1:
    perror("fork");
    exit(1);

    case 0:
    printf("Hello from child [%d-%d]\n",pid,n);
    exit(0);

    default:
        printf("Hello from parent [%d-%d]\n",pid,n);
}
return 0;
}
