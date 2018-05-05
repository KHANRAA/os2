//
// Created by root on 5/5/18.
//
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdio.h>

int main()
{
    int n,f,buff[50];
    f=open("test1",O_RDONLY);
    n=read(f,buff,5);
    write(1,buff,n);
    printf("\nafter that \n");
    fflush(stdout);

    n=read(f,buff,5); //current position of the pointer at 5
    write(1,buff,n);
    printf("\nafter that\n");
    fflush(stdout);

    lseek(f,0,SEEK_SET);   //set pointer to 0
    n=read(f,buff,4);
    write(1,buff,n);
    printf("\nafter that \n");
    fflush(stdout);

    lseek(f,2,SEEK_CUR);   //move pointer from current
    n=read(f,buff,4);
    write(1,buff,n);
    printf("\naftre that\n");
    fflush(stdout);
    close(f);
    f=open("test1",O_RDONLY);
    lseek(f,-6,SEEK_END);
    n=read(f,buff,5);
    write(1,buff,n);
    printf("\nafter that\n");
    fflush(stdout);

    exit(EXIT_SUCCESS);


}

