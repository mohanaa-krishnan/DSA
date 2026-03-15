#include<stdio.h>
#include<stdlib.h>
#define size 1000
int  main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int hash[size]={0};
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0 && arr[i]<size)
        {
            hash[arr[i]]++;
        }
    }
    for(int i=0;i<size;i++)
    {
        if(hash[i]>0)
        {
            printf("%d %d\n",i,hash[i]);
        }
    }
}