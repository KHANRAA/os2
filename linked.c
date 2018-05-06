//
// Created by root on 5/6/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

int main()
{
    int a[50],i,n,al,start,length;
    char ch;
    memset(a,0,50 * sizeof(int));
    printf("Enter the no of blocks already allocated\n");
    scanf("%d",&n);
    if(n>0) {
        printf("\nEnter the blocks\n");
        for (i = 0; i < n; i++)
        {
            scanf("%d",&al);
            assert(al>0 && al<50);
            a[al]=1;
        }
    }
    while(1) {
        printf("\nEnter the starting block\n");
        scanf("%d",&start);
        printf("\nEnter the length\n");
        scanf("%d",&length);
        system("clear");
        for (i = start; i < (start + length); i++) {
            if (a[i]==0){
                a[i]=1;
                printf("\n%d ->%d",i,a[i]);
            }else
            {
                printf("\nBlock %d already allocated",i);
                length++;
            }
        }
        if(i==(start+length))
        {
            printf("\nFile Allocated Successfully\n");

        }else
        {
            printf("Allocation failed!\n");
        }
        printf("\nDo you want to allocate more files? (y/n)");
        scanf("\r%c",&ch);
        if(ch=='n')
            break;
    }
exit(EXIT_SUCCESS);
}
