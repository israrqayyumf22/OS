#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("Starting Task 1\n");

    printf("Parent Process ID: %d\n", getpid());

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        printf("Child Process ID (inside child): %d\n", getpid());
    } else {
        printf("Child Process ID (inside parent): %d\n", pid);
    }

    return 0;
}
