//
// Created by root on 5/5/18.
//
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/types.h>
#include <stdio.h>
int main()
{
    int f,n;
    char buff[50],ans[50];
    printf("Enter the data to be write on the file\n");
    fflush(stdout);
    n=read(0,buff,50);
    f=open("test1",O_CREAT|O_WRONLY,0777);
    write(f,buff,n);
    close(f);
    f=open("test1",O_RDONLY);
    read(f,ans,n);
    close(f);
    write(1,ans,n);
    exit(EXIT_SUCCESS);
}

