//
// Created by root on 5/6/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int res;
    char buff[]="Hello Akash!";
    res=open("fifo1",O_WRONLY);
    if(res==-1)
    {
        perror("Pipe does not exist.\n");
        exit(EXIT_FAILURE);
    }
    write(res,buff,strlen(buff));
    printf("\nProcess %d terminated.\n",getpid());
    exit(EXIT_SUCCESS);


}