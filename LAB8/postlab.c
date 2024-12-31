#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int shared_data = 0; // Shared data
sem_t wrt; // Semaphore for writers
int read_count = 0; // Active readers count

void *reader(void *arg) {
    int id = *(int *)arg;
    __sync_fetch_and_add(&read_count, 1); // Atomically increment read_count
    if (read_count == 1) sem_wait(&wrt); // First reader locks writers

    printf("Reader %d: Reading data = %d\n", id, shared_data);

    __sync_fetch_and_sub(&read_count, 1); // Atomically decrement read_count
    if (read_count == 0) sem_post(&wrt); // Last reader unlocks writers

    return NULL;
}

void *writer(void *arg) {
    int id = *(int *)arg;
    sem_wait(&wrt);
    shared_data += 20; // Change the increment to 20
    printf("Writer %d: Writing data = %d\n", id, shared_data);
    sem_post(&wrt);
    return NULL;
}

int main() {
    pthread_t r1, r2, r3, w1, w2;
    int reader_ids[3] = {1, 2, 3};
    int writer_ids[2] = {1, 2};

    sem_init(&wrt, 0, 1);

    pthread_create(&r1, NULL, reader, &reader_ids[0]);
    pthread_create(&w1, NULL, writer, &writer_ids[0]);
    pthread_create(&r2, NULL, reader, &reader_ids[1]);
    pthread_create(&w2, NULL, writer, &writer_ids[1]);
    pthread_create(&r3, NULL, reader, &reader_ids[2]);

    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w2, NULL);
    pthread_join(r3, NULL);

    sem_destroy(&wrt);

    return 0;
}
