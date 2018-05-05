//
// Created by root on 5/5/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

void * fib_func(void * arg){
    int n=atoi(arg);
    int n1=0,n2=1,next;
    printf("The fibonaci series of the no is---------->\n");
    for(int i=0;i<=n;i++)
    {
        printf("%d--",n1);
        next=n1+n2;
        n1=n2;
        n2=next;
    }
    //fflush(stdout);
    pthread_exit("\nThread fibonaci completed..........!\n");

}

void * fact_func(void * arg)
{
    int n=atoi(arg);
    int fact=1;
    for(int i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    pthread_exit((void *)fact);
}


int main()
{
    int n;
    pthread_t fib_thread,fact_thread;
    char *buff[50];
    printf("Enter the no for fact and fibonaci\n");
    fflush(stdout);
    n=read(0,buff,50);
    void * fib_res;
    void * fact_res;
    pthread_create(&fib_thread,NULL,fib_func,(void *)buff);
    pthread_join(fib_thread,&fib_res);
    pthread_create(&fact_thread,NULL,fact_func,(void*)buff);
    pthread_join(fact_thread,&fact_res);

    printf("\nwaiting------------ %s",fib_res);
    printf("\nThe factorial of the number is %d\n",fact_res);

    exit(EXIT_SUCCESS);

}
