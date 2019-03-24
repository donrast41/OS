#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void signal_handler(int sig_num){

   printf("\n Signalint: (%d) \n", sig_num);

}

int main(void){

    signal(SIGINT, signal_handler);
    while(1){
        sleep(10);
        return EXIT_SUCCESS;
    }

}
