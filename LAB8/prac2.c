#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *thread_function(void *arg) {
	printf("Thread is running...\n");
	sleep(3); 
	printf("Thread finished its work.\n");

	return NULL;
	}
int main() {
	pthread_t thread;
	int result;
	// Create a thread
	result = pthread_create(&thread, NULL, thread_function, NULL);
	if (result != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	
	result = pthread_detach(thread);
	if (result != 0) {
		perror("Thread detachment failed");
		exit(EXIT_FAILURE);
	}
	printf("Main program continues...\n");
	// Main program continues its execution without waiting for the thread
	sleep(5); // Just to show that the main program continues
	printf("Main program finished.\n");
	return EXIT_SUCCESS;
}
