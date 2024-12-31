#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void *sum(void *arg){
    int *num1=(int*)arg;
    int *num2=(int*)arg+1;
    int r=*num1+ *num2;
    printf("\nSum of numbers are: %d",r);
    return NULL;
}
void* mul(void* arg){
    int* num1=(int*)arg;
    int* num2=(int*)arg+1;
    int r=*num1 * *num2;
    printf("\nMultiplication of numbers are: %d",r);
    return NULL;
}
void* sub(void* arg){
    int* num1=(int*)arg;
    int* num2=(int*)arg+1;
    int r=*num1 - *num2;
    printf("\nSubtraction of numbers: %d",r);
    return NULL;
}
int main(){
    int num[2];
    for(int i=0;i<2;i++){
        printf("Enter number %d : ",i+1);
        scanf("%d",&num[i]);
    }
    pthread_t thread1,thread2,thread3;
    
    pthread_create(&thread1,NULL,sum,(void*)num);
    pthread_create(&thread3,NULL,sub,(void*)num);
    pthread_create(&thread2,NULL,mul,(void*)num);
    
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    printf("\nMain Ends\n");
}
