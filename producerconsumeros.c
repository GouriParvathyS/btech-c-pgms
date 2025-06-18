#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

Sem_t empty;
Sem_t full;
Pthread_mutex_t mutex;

Int buffer[BUFFER_SIZE];
Int in = 0;
Int out = 0;

Void *producer(void *arg) {
    Int item = 1;
    While (1) {
        Sem_wait(&empty);
        Pthread_mutex_lock(&mutex);
        Buffer[in] = item;
        Printf(“Produced item %d\n”, item);
        Item++;
        In = (in + 1) % BUFFER_SIZE;
        Pthread_mutex_unlock(&mutex);
        Sem_post(&full);
    }
}

Void *consumer(void *arg) {
    While (1) {
        Sem_wait(&full);
        Pthread_mutex_lock(&mutex);
        Int item = buffer[out];
        Printf(“Consumed item %d\n”, item);
        Out = (out + 1) % BUFFER_SIZE;
        Pthread_mutex_unlock(&mutex);
        Sem_post(&empty);
    }
}

Int main() {
    Pthread_t producer_thread, consumer_thread;

    Sem_init(&empty, 0, BUFFER_SIZE);
    Sem_init(&full, 0, 0);
    Pthread_mutex_init(&mutex, NULL);

    Pthread_create(&producer_thread, NULL, producer, NULL);
    Pthread_create(&consumer_thread, NULL, consumer, NULL);

    Pthread_join(producer_thread, NULL);
    Pthread_join(consumer_thread, NULL);

    Sem_destroy(&empty);
    Sem_destroy(&full);
    Pthread_mutex_destroy(&mutex);

    Return 0;
}
