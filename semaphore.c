//
// Created by root on 5/6/18.
//
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

int shared=1;
sem_t s;

void * fun1();
void * fun2();

int main()
{
    // 2nd arg is no od process sharing the semaphore
    sem_init(&s,0,1);

    pthread_t one,two;

    pthread_create(&one,NULL,fun1,NULL);
    pthread_create(&two,NULL,fun2,NULL);

    pthread_join(one,NULL);
    pthread_join(two,NULL);

    printf("The final value of the shared variable is :%d\n",shared);
    exit(EXIT_SUCCESS);
}

void * fun1()
{
    int x;
    sem_wait(&s);
    x=shared;
    x++;
    sleep(1);
    shared=x;
    sem_post(&s);
    pthread_exit(NULL);
}

void * fun2()
{
    int y;
    sem_wait(&s);
    y=shared;
    y--;
    sleep(1);
    shared=y;
    sem_post(&s);
    pthread_exit(NULL);
}