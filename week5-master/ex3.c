#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int *buffer;
int i = 0;

pthread_mutex_t mlv = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bq_not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t bq_not_empty = PTHREAD_COND_INITIALIZER;

void *consumer();
void *producer();

int main() {
    pthread_t p_th_id, c_th_id;
    buffer = (int *) malloc(sizeof(int) * 100);
    pthread_create(&p_th_id, NULL, producer, NULL);
    pthread_create(&c_th_id, NULL, consumer, NULL);
    pthread_join(p_th_id, NULL);
    pthread_join(c_th_id, NULL);

    return 0;
}
void *consumer() {
    while (1) {
        pthread_mutex_lock(&mlv);

        if (i == -1) {
            pthread_cond_wait(&bq_not_empty, &mlv);
        }
        printf("\n consumer:%d\n", i--);
        pthread_mutex_unlock(&mlv);
        pthread_cond_signal(&bq_not_full);
    }
}
void *producer() {
    while (1) {
        pthread_mutex_lock(&mlv);

        if (i == 100) {
            pthread_cond_wait(&bq_not_full, &mlv);
        }
        buffer[i] = 1;
        i++;
        printf("\n producer:%d\n", i);
        pthread_mutex_unlock(&mlv);
        pthread_cond_signal(&bq_not_empty);
    }
}
