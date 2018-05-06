//
// Created by root on 5/7/18.
//

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>

int main()
{
    int shmId;
    void * shared_mem;
    shmId=shmget((key_t)10,1000,0666);
    printf("Key of the shared memoey is: %d",shmId);

    shared_mem=shmat(shmId,NULL,0);
   // printf("Process attached at %x\n",(int *)shared_mem);
    printf("Data read form shared memory : %s",shared_mem);
    exit(EXIT_SUCCESS);
}