//
// Created by root on 5/6/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int res,n;
    char buff[100];
    res=open("fifo1",O_RDONLY);
    if(res==-1)
    {
        perror("Pipe does not exists\n");
        exit(EXIT_FAILURE);

    }
    n=read(res,buff,sizeof(buff));
    printf("data read: %s",buff);
    printf("\n Total bytes read: %d",n);
    printf("Process %d terminated \n",getpid());
    exit(EXIT_SUCCESS);

}
