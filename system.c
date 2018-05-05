//
// Created by root on 5/5/18.
//
#include <stdlib.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
    printf("Before system call:\n ");
    system("ls");
    printf("\n\nAfter system call:\n ");
    exit(EXIT_SUCCESS);
}


