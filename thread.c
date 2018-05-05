//
// Created by root on 5/5/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

typedef struct arguments{
    int arg1;
    int arg2;
}args;


void * thread_func(void *arguments){
    args * arg=arguments;
    int sum = arg->arg1 + arg->arg2;

    printf("Inside thread\n");
    printf("First argument: %d\n Second Argument: %d",arg->arg1,arg->arg2);
    pthread_exit((void *) sum);

}

int main()
{
 pthread_t  a_thread; // thread declaration
 args arg;
 void * sum;
 arg.arg1=1;
 arg.arg2=2;
 pthread_create(&a_thread,NULL,thread_func,&arg);
 pthread_join(a_thread, &sum);
 printf("\nthread finish. %d\n", (int) sum);

 exit(EXIT_SUCCESS);

}

