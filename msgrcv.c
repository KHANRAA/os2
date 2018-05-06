//
// Created by root on 5/6/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>

int main()
{
    int msgId;
    char buff[100];
    msgId=msgget((key_t)10,0666);
    printf("Message read from the queue is: ");
    msgrcv(msgId,&buff,sizeof(buff),0,IPC_NOWAIT);
    printf("%s",buff);
    exit(EXIT_SUCCESS);
}
