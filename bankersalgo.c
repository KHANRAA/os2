//
// Created by root on 5/7/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int p; // no of process
    printf("Enter the no of process\n");
    scanf("%d",&p);

    int allocation[p]; // no of allocation resources
    int max[p]; // no of max resource srequired
    int need[p]; // need calcurat
    int flag[p]; //keep track

    int available; //no of instances available resources
    int sequence[p+1000],k=0; // store the result
    int stat=1;// 0-> System unsafe \
                   1-> safe
    int i,j;

    //initially no process has been finished set all them zero
    memset(flag,0,p * sizeof(int));
    printf("\nEnter the nuber of instance s of the respoure: ");
    scanf("%d",&available);

    for (int i = 0; i <p ; ++i) {
        printf("\nEnter currnet aloocatioin process p[%d]: ",i);
        scanf("%d",&allocation[i]);
        printf("\nEnter mazimum requirement of process p[%d]:",i);
        scanf("%d",&max[i]);

        need[i]=max[i]-allocation[i];
        fflush(stdout);
    }
    printf("\n");

    for(int i=0;i<p;i++)
    {
        for (int j = 0; j <p ; ++j) {
            if(flag[j]==0&& need[j]<=available )
            {
                available+=allocation[i];
                flag[j]=1;
                printf("\nProcess p[%d] has been allocated the resources\n",j);
                sequence[k++]=j;
            }
        }

    }

    for (int i = 0; i <p ; ++i) {
        if(flag[i]==0)
        {
            stat=0; //unsafe state
            break;
        }

    }
    if(stat==0)
    {
        printf("\nSystem is in unsafe state");
        printf("Safe sequence is: ");
        for(i=0;i<k;i++)
        {
            printf("%d",sequence[i]);
        }
    }
    printf("\n");
    exit(EXIT_SUCCESS);



}
