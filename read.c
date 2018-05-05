//
// Created by root on 5/5/18.
//

#include<stdlib.h>
#include<unistd.h>
int main()
{
    int n;
    char buff[50];
    n=read(0,buff,50);
    write(1,buff,n);
    exit(EXIT_SUCCESS);
}

