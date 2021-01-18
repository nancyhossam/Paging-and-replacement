#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include<string.h>

int pages[100];
int NoOfPages=0;
int *buffer;
int n=0;
int main()
{
    int temp=1;
    char type[10];
    int i=0;

scanf("%d",&n);

    scanf("%s",type);
    while(1)
    {
        scanf("%d",&temp);
        if(temp==-1)
            break;
        pages[i]=temp;
        NoOfPages++;
        i++;
    }
    buffer=(int*)calloc(n,sizeof(int));
    int b=0;
    for(int u=0; u<n; u++)
        buffer[u]=-1;

    printf("Replacement Policy = %s\n",type);
    printf("-------------------------------------\n");
    printf("Page   Content of Frames\n");
    printf("----   -----------------\n");
    if(strcmp(type, "FIFO") == 0)
        FIFO();

    else if (strcmp(type, "LRU") == 0)
        LRU();
    else if (strcmp(type, "CLOCK") == 0)
        CLOCK();
        else if (strcmp(type, "OPTIMAL") == 0)
        OPTIMAL();

    printf("-------------------------------------\n");
    printf("Number of page faults = %d\n",count);

    return 0;
}
