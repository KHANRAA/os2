//
// Created by root on 5/7/18.
//
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    pid_t p;
    int fd[2];
    pipe(fd);
    p=fork();

    if(p<0)
    {
        perror("Fork Failed!!!!\n");
        exit(EXIT_FAILURE);

    }else if(p==0)
    {
        //inside child
        sleep(1);
        close(fd[1]);
        char message[100];
        printf("Child Received: ");
        fflush(stdout);
        write(1,message,read(fd[0],message,sizeof(message)));

    }else
    {
        //indside parent process
        close(fd[0]); //close the read end
        char message[]="Hello AKASH!!!!!";
        write(fd[1],message,strlen(message));
        wait(NULL);
        printf("\n");
    }

exit(NULL);


}