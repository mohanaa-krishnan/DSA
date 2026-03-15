#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int ans[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=0;
    }
    int stack[n];
    int top=-1;
    for(int i=0;i<n;i++)
    {
        while(top!=-1 && arr[i]>arr[stack[top]])
        {
            int prev=stack[top];
            top--;
            ans[prev]=i-prev;

        }
        top++;
        stack[top]=i;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",ans[i]);
    }
}