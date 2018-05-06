//
// Created by root on 5/6/18.
//
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
int main(){
    DIR * dr;
    struct dirent * ds;
    //system("/root/Documents");
    dr=opendir("/root/Documents");
    if(dr==NULL){
        perror("Directry no found");
        exit(EXIT_FAILURE);
    }
    else
    {
        while((ds=readdir(dr))!=NULL)
        {
            printf("Name: \t%s\n" \
                   "Type:\t%d\n" \
                   "Inode No:\t%lld\n\n" \
                    ,ds->d_name,ds->d_type,ds->d_ino);
        }
        closedir(dr);
    }
    exit(EXIT_SUCCESS);
}
