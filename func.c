#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include<string.h>
int count=0;
void PrintBuffer()
{
    for(int i=0; i<n; i++)
    {
        if(buffer[i]==-1)
            break;
        else
            printf("%02d ",buffer[i]);
    }
    printf("\n");
}
int AlreadyExist(int page)
{
    for(int i=0; i<n; i++)
    {
        if(page==buffer[i])
            return i;

    }
    return -1;
}
int FIFO()
{
    int b=0;
    int temp;
    for(int i=0; i<NoOfPages; i++)
    {
        int exist=AlreadyExist(pages[i]);
        if(exist!=-1)
        {
            printf("%02d     ",pages[i]);
        }
        else
        {
            if(buffer[b%n]!=-1)
            {
                printf("%02d F   ",pages[i]);
                count ++;

            }
            else
            {
               printf("%02d     ",pages[i]);
            }
            buffer[b%n]=pages[i];
            b++;
        }
        PrintBuffer();
    }
}
void LRU()
{
    int b=0;
    int* used=calloc(n,sizeof(int));
    for(int i=0; i<n; i++)
    {
        used[i]=0;
    }
    int Recentused=0;
    for(int i=0; i<NoOfPages; i++)
    {
        int exist=AlreadyExist(pages[i]);
        if(exist!=-1)
        {
            printf("%02d     ",pages[i]);
            used[exist]=Recentused;
            Recentused++;
        }
        else
        {
            if(b>=n)
            {
                printf("%02d F   ",pages[i]);
                count ++;
                int mini=100000;
                int ind;
                for(int j=0; j<n; j++)
                {
                    if(mini>used[j])
                    {
                        ind =j;
                        mini=used[j];

                    }
                }
                buffer[ind]=pages[i];
                used[ind]=Recentused;
                Recentused++;
            }
            else
            {
                printf("%02d     ",pages[i]);
                buffer[b]=pages[i];
                used[b]=Recentused;
                Recentused++;
                b++;

            }




        }
        PrintBuffer();
    }


}
void CLOCK()
{
    int *bit=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    bit[i]=0;
          int j=0;

    for(int i=0; i<NoOfPages; i++)
    {
        int exist=AlreadyExist(pages[i]);
        if(exist!=-1)
        {
            bit[exist]=1;
             printf("%02d     ",pages[i]);
        }
        else
        {

            while(bit[j%n]!=0)
            {
                bit[j%n]=0;
                j++;
            }
            buffer[j%n]=pages[i];
            bit[j%n]=1;
            j++;
            if(j>n)
            {
               printf("%02d F   ",pages[i]);
                count++;
            }

            else  printf("%02d     ",pages[i]);

        }
        PrintBuffer();
    }
}
void OPTIMAL()
{int b=0;
 for(int i=0; i<NoOfPages; i++)
    {
     int exist=AlreadyExist(pages[i]);
        if(exist!=-1)
        {
       printf("%02d     ",pages[i]);

        }
        else
        {
          if(b<n)
          {
          printf("%02d     ",pages[i]);
          buffer[b]=pages[i];
          b++;
          }else
          {
          int arr[n];
          for(int j=0;j<n;j++)
          arr[j]=-1;
          for(int k=i+1;k<NoOfPages;k++)
          {
          for(int f=0;f<n;f++)
          {
                if(pages[k]==buffer[f])
                {
                if (arr[f]==-1)
                   arr[f]=k;
                }

          }}
          int max=-2;
          int minindex;
          for(int j=0;j<n;j++)
          { if(arr[j]==-1)
          {minindex=j;
          break;
          }
          if(arr[j]>max)
         { max=arr[j];
          minindex=j;}

          }
          buffer[minindex]=pages[i];
         printf("%02d F   ",pages[i]);
                count++;



          }

        }
        PrintBuffer();

    }

}
