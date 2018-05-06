//
// Created by root on 5/7/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    FILE * rd;
    char buff[100];

    sprintf(buff,"Hello Akash!!!");

    rd=popen("wc -c","w");

    fwrite(buff,sizeof(char),strlen(buff),rd);

    pclose(rd);

    exit(EXIT_SUCCESS);
}