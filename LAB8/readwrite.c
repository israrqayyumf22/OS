#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int data = 0;
int readers_count = 0;
pthread_mutex_t readers_count_lock;
sem_t resource_lock;

void* reader(void* arg) {
    int reader_id = *((int*)arg);
    while (1) {
        pthread_mutex_lock(&readers_count_lock);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&resource_lock);
        }
        pthread_mutex_unlock(&readers_count_lock);

        printf("Reader %d is reading data: %d\n", reader_id, data);
        sleep(1);

        pthread_mutex_lock(&readers_count_lock);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&resource_lock);
        }
        pthread_mutex_unlock(&readers_count_lock);

        sleep(1);
    }
    return NULL;
}

void* writer(void* arg) {
    int writer_id = *((int*)arg);
    while (1) {
        sem_wait(&resource_lock);

        data++;
        printf("Writer %d is writing data: %d\n", writer_id, data);
        sleep(2);

        sem_post(&resource_lock);

        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t readers[5], writers[2];
    int reader_ids[5], writer_ids[2];

    pthread_mutex_init(&readers_count_lock, NULL);
    sem_init(&resource_lock, 0, 1);

    for (int i = 0; i < 5; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }
    for (int i = 0; i < 2; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }

    pthread_mutex_destroy(&readers_count_lock);
    sem_destroy(&resource_lock);

    return 0;
}

