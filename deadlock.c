//
// Created by root on 5/6/18.
//
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

pthread_mutex_t first_mutex;
pthread_mutex_t second_mutex;

void * fun1();
void * fun2();

int main()
{
    pthread_mutex_init(&first_mutex,NULL);
    pthread_mutex_init(&second_mutex,NULL);

    pthread_t one,two;

    pthread_create(&one,NULL,fun1,NULL);
    pthread_create(&two,NULL,fun2,NULL);

    pthread_join(one,NULL);
    pthread_join(two,NULL);

    exit(EXIT_SUCCESS);
}

void * fun1()
{
    pthread_mutex_lock(&first_mutex);
    printf("\nThread one aquired lock on: '%s' \n","first_mutex");
    sleep(1);
    pthread_mutex_lock(&second_mutex);
    printf("Thread one aquired lock on: '%s'\n","second_mutex");

    pthread_mutex_unlock(&second_mutex);
    printf("Thread one aquired unlock on '%s'\n","second_mutex");

    pthread_mutex_unlock(&first_mutex);
    printf("Thread one aquired unlock on '%s'\n","first_mutex");

}

void * fun2()
{
    pthread_mutex_lock(&second_mutex);
    printf("Thread two aquired lock on '%s'\n","second_mutex");
    sleep(1);
    pthread_mutex_lock(&first_mutex);
    printf("Thread two aquired lock on '%s'\n","first_mutex");
    pthread_mutex_unlock(&first_mutex);
    printf("Thread two aquired unlock on '%s'\n","first_mutex");
    pthread_mutex_unlock(&second_mutex);
    printf("Thread two aquired unlock on '%s'\n","second_mutex");

}