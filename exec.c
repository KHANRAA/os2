//
// Created by root on 5/6/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    printf("Before  execution of the process");
    execl("/bin/ps","ps","-a",NULL); //replace a process with current
    printf("After execl");

}

