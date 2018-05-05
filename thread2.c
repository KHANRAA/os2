//
// Created by root on 5/5/18.
//
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void * thread_func(void * arg){
    int n=atoi(arg);
    int sum=0;

    for(int i=0;i<=n;++i)
    {
        sum=sum+i;
    }
    pthread_exit((void *)sum);

}

int main()
{

pthread_t a_thread;
char * a="5";
void * result;
pthread_create(&a_thread,NULL,thread_func,(void *)a);
pthread_join(a_thread,&result);
printf("Thread finished and returned %d, ",(int)result);

exit(EXIT_SUCCESS);

}

