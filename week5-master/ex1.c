#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int threads[50];

void *message(int i);

void sequential_thread()
{
    int race, i;
    for (i = 0; i < 50; i++) {
        race = pthread_create(&threads[i], NULL, message, (void*)i);
        if (race) {
            printf("\n error %d \n", race);
            exit(1);
        }
        rc = pthread_join(threads[i], NULL);
        printf("\n full thread %d. new thread (%d) in order %d.\n", (int) pthread_self(), threads[i], i);
    }
}

void *message(int i) {
    printf("Hello I am thread :- %d - step by step %d \n", (int) pthread_self(), i);
    pthread_exit(NULL);
}

void parallel_thread()
{
    int race, i;
    for (i = 0; i < 50; i++) {
        race = pthread_create(&threads[i], NULL, message, (void*)i);
        if (race) {
            printf("\n error %d \n", race);
            exit(1);
        }
    }
    for (i = 0; i < 50; i++) {
        race = pthread_join(threads[i], NULL);
        printf("\n full thread %d. new thread (%d) in order %d.\n", (int) pthread_self(), threads[i], i);
    }
}

int main(int argc, char *argv[]) {
    sequential_thread();

}


