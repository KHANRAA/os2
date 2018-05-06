//
// Created by root on 5/7/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <sys/sem.h>
int main()
{
    FILE* rd;
    char buff[100];
    rd=popen("ls","r");
    fread(buff,1, sizeof(buff),rd);
    printf("%s",buff);
    pclose(rd);
    exit(EXIT_SUCCESS);
}