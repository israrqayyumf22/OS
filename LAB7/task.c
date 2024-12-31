#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int age;
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        printf("Enter your age: ");
        scanf("%d", &age);
        _exit(age);
    } else {
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            age = WEXITSTATUS(status);
            printf("The age entered by the child is: %d\n", age);
        }
    }

    return 0;
}
