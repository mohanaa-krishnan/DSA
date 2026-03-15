#include<limits.h>
#include<stdio.h>
int sliding(int ar[],int a,int b);
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);
   int  result=sliding(arr,n,k);
   printf("%d",result);
    return 0;
}
int sliding(int ar[],int a,int b)
{
int csum=0;
int msum=INT_MIN;
for(int i=0;i<b;i++)
{
    csum+=ar[i];
}
if(csum>msum)
{
    msum=csum;
}
for(int i=b;i<a;i++)
{
    csum=csum-ar[i-b]+ar[i];
    if(csum>msum)
    {
        msum=csum;
    }
}
return msum;
}