// Online C compiler to run C program online
#include <stdio.h>
int recursion(int arr[],int mid,int value,int low,int high);

int main() {
   int n;
   
   scanf("%d",&n);
   int arr[n];
   for(int i=0;i<n;i++)
   {
   scanf("%d",&arr[i]);
   }
   int value;
   scanf("%d",&value);
   int mid;
   int low=0,high=n-1;
   //printf("%d\n",high);
   mid=low+(high-low)/2;
   printf("%d",recursion(arr,mid,value,low,high));
    return 0;
}

int recursion(int arr[],int mid,int value,int low,int high)
{
    if(low<=high)
    {
    mid=low+(high-low)/2;
    
    
    if(arr[mid]==value)
    {
        return mid;      
    }
    if(value<arr[mid])
    {
    high=mid-1;
    mid=low+(high-low)/2;
    return recursion(arr,mid,value,low,high);
    }
     if(value>arr[mid])
    {
    low=mid+1;
    mid=low+(high-low)/2;
    return recursion(arr,mid,value,low,high);
    }
    
    }
   return -1;
   
    
}