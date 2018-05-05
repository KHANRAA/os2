//
// Created by root on 5/5/18.
//
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t p;
    p=fork();
    if(p==0){
        sleep(30);
        printf("in child process");
    }else if(p>0)
    {
        printf("In Parent process\n");
    }else
    {
        perror("Failed!!!!!!");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
