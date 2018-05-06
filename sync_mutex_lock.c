//
// Created by root on 5/6/18.
//
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
int shared=1;
pthread_mutex_t l;

void * fun1();
void * fun2();
 int main()
 {
     pthread_mutex_init(&l,NULL);
     pthread_t one,two;

     pthread_create(&one,NULL,fun1,NULL);
     pthread_create(&two,NULL,fun2,NULL);

     pthread_join(one,NULL);
     pthread_join(two,NULL);

     printf("The final value of the shared variable is: %d",shared);

     exit(EXIT_SUCCESS);
 }

 void * fun1()
 {
     int x;
     pthread_mutex_lock(&l);
     x=shared;
     x++;
     sleep(1);
     shared=x;
     pthread_mutex_unlock(&l);
     pthread_exit(NULL);

 }

 void * fun2()
 {
     int y;
     pthread_mutex_lock(&l);
     y=shared;
     y--;
     sleep(1);
     shared=y;
     pthread_mutex_unlock(&l);
     pthread_exit(NULL);

 }