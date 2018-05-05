//
// Created by root on 5/5/18.
//
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t p;
    p=fork();
    if(p<0)
    {
      perror("Failure!!!!!!!!!!!");
      exit(EXIT_FAILURE);
    }else if(p==0) {
        //printf("in child process\n");
        for (int i = 0; i <= 5; i++) {
            printf("C:%d ", i);
            fflush(stdout);
            sleep(1);

            }

        } else {

        //printf("In parent process\n");
        for(int i=6;i<=10;i++)
        {
            printf(" P:%d ",i);
            fflush(stdout);
            sleep(1);
        }
    }
exit(EXIT_SUCCESS);
}
