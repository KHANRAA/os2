//
// Created by root on 5/6/18.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{

    int a[50],start,length;
    int i;
    char ch;
    memset(a,0,50*sizeof(int));

    while(1)
    {
        printf("Enter the starting block\n");
        scanf("%d",&start);
        printf("Enter the length\n");
        scanf("%d",&length);
        for(i=start;i<(start+length);i++)
        {
            if(a[i]==0)
            {
                a[i]=1;
                printf("%d -> %d\n",i,a[i]);

            }else
            {
                printf("block %d already allocated.\n",i);
                break;
            }
        }
        if(i==(start+length)){
            printf("\nFile allocated successfully to disk.\n");
        }
        printf("\n Do you want to allocate more filed? (y/n)");
        scanf("\r%c",&ch);
        if(ch=='n')
            break;
    }
exit(EXIT_SUCCESS);
}

