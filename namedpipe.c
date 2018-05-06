//
// Created by root on 5/6/18.
//
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    int res=mkfifo("fifo1",0777);
    printf("Named pipe created!!\n");
    exit(EXIT_SUCCESS);
}
