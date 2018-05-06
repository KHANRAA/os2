//
// Created by root on 5/6/18.
//
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>
#define MAX 5
sem_t s;
int full=0;
int empty=MAX;
int i=-1;
int buff[MAX];


void * producer(void * arg)
{
    sem_wait(&s);
    if(full<MAX)
    {
        buff[++i]=(int)arg;
        empty-=1;
        full+=1;
        printf("Producer produces: %d\n",(int)arg);
    }else
    {
        printf("nothing to produce!!!!\n");
    }
     sleep(1);
    sem_post(&s);

}

void * consumer()
{
    sem_wait(&s);
    if(full>0){
        full-=1;
        empty+=1;
        printf("\nConsumer consumes %d\n",buff[i--]);
    } else{
        printf("Nothing to Consume!!!!!!\n");
    }
    sleep(1);
    sem_post(&s);
}


int main()
{
    int prun,crun;
sem_init(&s,0,1);
pthread_t p,c1;
int k=120;

    printf("Enter no of time producer will run\n");
    scanf("%d",&prun);
    for(int j=0;j<prun;j++) {
        pthread_create(&p,NULL,producer,(void *)k);
    }

    printf("\nEnter no of time consumer will run\n");
    scanf("%d",&crun);
    for(int j=0;j<crun;j++) {

        pthread_create(&c1, NULL, consumer, NULL);
    }//pthread_create(&c2,NULL,consumer,NULL);

    pthread_join(p, NULL);
    pthread_join(c1, NULL);

//pthread_join(c2,NULL);
exit(EXIT_SUCCESS);

}

