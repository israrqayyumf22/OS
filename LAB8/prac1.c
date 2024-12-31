#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
// Function to be executed by the thread
void *thread_function(void *arg) {
	int *thread_id = (int *)arg; // Cast the argument to an int pointer
	printf("Thread ID: %d\n", *thread_id);
	return NULL;
}
int main() {
pthread_t tid; // Thread identifier
int thread_id = 100; // Unique ID for the thread
// Create a new thread
int result = pthread_create(&tid, NULL, thread_function, &thread_id);
if (result != 0) {
perror("Thread creation failed");
return -1;
}
// Wait for the thread to finish execution
pthread_join(tid, NULL);
printf("Main thread is done\n");
return 0;
}
