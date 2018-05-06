//
// Created by root on 5/7/18.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/shm.h>
//#include <sys/ipc.h>
int main()
{
    void * shared_mem;
    char buff[100];
    int shmId,n;
    shmId=shmget((key_t)10,1000,0666|IPC_CREAT);
    printf("Key of shared variable is: %d\n",shmId);
    shared_mem=shmat(shmId,NULL,0);

  //  printf("Process attached at %x\n",(int *)shared_mem);

    printf("Enter data to write to shared memoery:");
    fflush(stdout);

    read(0,buff,sizeof(buff));

    strcpy(shared_mem,buff);
    printf("Data written to shared memory: %s",shared_mem);

    exit(EXIT_SUCCESS);




}


