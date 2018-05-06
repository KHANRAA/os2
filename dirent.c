//
// Created by root on 5/6/18.
//

#include<dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{

    DIR * dr;
    struct dirent * ds;
    //mkdir("AKASH",0777);
    dr=opendir("AKASH");
    if(dr==NULL)
    {
        perror("Error in opening");
        exit(EXIT_FAILURE);
    }else
    {
        while((ds=readdir(dr))!=NULL){
            printf("Name:\t%s\n" \
                    "TYPE:\t%d\n" \
                     "Inode Number:\t%llu\n\n" \
                        ,ds->d_name,ds->d_type,ds->d_ino
            );
        }closedir(dr);
    }
exit(EXIT_SUCCESS);
}
