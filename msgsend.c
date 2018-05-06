//
// Created by root on 5/7/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/msg.h>

int main()
{
    int msgId;
    char buff[100];
    msgId=msgget((key_t)10,0666|IPC_CREAT);

    printf("Enter MEssage: ");
    fflush(stdout);
    read(0,buff,sizeof(buff));
    msgsnd(msgId,&buff,strlen(buff),0);
    printf("Msg send!!!\n");
    exit(EXIT_SUCCESS);
}
