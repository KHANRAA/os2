//
// Created by root on 5/5/18.
//

// create a zombie process to explain ..........

#include "zombie.h"

int main()
{
    // Fork returns process id
    // in parent process
    pid_t child_pid = fork();

    // Parent process
    if (child_pid > 0) {
        sleep(30);
        printf("\nParent\n");
        // Child process
    }else{
        printf("\nChild\n");
        exit(0);
    }
    return 0;
}