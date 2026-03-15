#include<stdio.h>
#define size 1000
int main()
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
        if(arr[i]>0 && arr[i]<size )
        {
            hash[arr[i]]++;
        }
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int t;
        scanf("%d",&t);
        printf("%d %d\n",t,hash[t]);
    }
    return 0;
}
