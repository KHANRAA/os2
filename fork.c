//
// Created by root on 5/5/18.
//
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//  create the folling hirarachy
//
//                 p
//                / \
//               /   \
//              p1    p2
//

int main()
{

    pid_t p;
    p=fork();
    if(p==0){

        printf("Child process having ID:%d\n",getpid());
        printf("Parent of child %d is %d\n",getpid(),getppid());

    }else if(p>0){
        //inside the parent process
        p=fork();
        if(p==0){
            // inside the second child process
            printf("Child process having ID :%d \n",getpid());
            printf("Parent of child %d is %d\n",getpid(),getppid());
            exit(EXIT_SUCCESS);
        }else if(p<0){
            perror("Fork Failed!\n");
            exit(EXIT_FAILURE);
        }

        wait(NULL);
        printf("Parent  process having id %d \n",getpid());

    }else {
        perror("Fork Failed!!!!!!");
        exit(EXIT_FAILURE);
    }
    return 0;

}