#include<stdlib.h>// Online C compiler to run C program online
#include <stdio.h>
#include<stdbool.h>
int *search(int arr[],int n,int *l,int value,int index);
int Index=0;
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    int *list=(int *)malloc(n*sizeof(int));
    list[0]=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int value;
    scanf("%d",&value);
    int *LIST=search(arr,n,list,value,0);
    int i=0;
    do
    {
        printf("%d ",LIST[i++]);
    }while(i<Index);

    return 0;
}

int *search(int arr[],int n,int *l,int value,int index)
{
    if(index>n-1)
    {
        //l[Index++]=-1;
        return l;
    }
    if(arr[index]==value)
    {
        printf("index:%d value:%d\n",index,arr[index]);
        l[Index++]=index;
        
    }
    return search(arr,n,l,value,index+1);
}