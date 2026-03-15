#include<stdio.h>
#include<stdlib.h>
#define size 1000
int hash[size];
int *creation(int a);
int main()
{
    int n;
    scanf("%d",&n);
    int *p;
    p=creation(n);
    for(int i=0;i<n;i++)
    {
        if(p[i]>0 && p[i]<size)
        {
            hash[p[i]]++;
        }
    }
    int max=0;
    int value;
    for(int i=0;i<size;i++)
    {
        if(hash[i]>max)
        {
            max=hash[i];
            
        }
    }
    int count =0;
    for(int i=0;i<size;i++)
    {
        if(hash[i]==max)
        {
            count++;
            value=i;
        }
    }
    if(count>1)
    {
        printf("NO MAX FREQUENCY EXSIST");
    }
    else{
        printf("%d",value);
    }
    
    return 0;
}
int *creation(int a)
{
int *arr=(int *)malloc(a*sizeof(int));
for(int i=0;i<a;i++)
{
    scanf("%d",&arr[i]);
}
return arr;
}