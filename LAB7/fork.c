#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){
    int pid;
    pid=fork();
    if(pid<0){
        perror("\nError while creating fork");
    }
    if(pid==0){
        printf("\n\nWe are in child process:");
        printf("\nChild ID is:%d",getpid());
        printf("\nParent ID is:%d",getppid());
    }
    else{
        wait(NULL);
        printf("\n\nWe are in the parent with ID is:%d\n",getpid());
    }
return 0;
}