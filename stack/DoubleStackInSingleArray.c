#include<stdio.h>
#define size 1000
int arr[size];
int main()
{
    int n;
    scanf("%d",&n);
    int top1=-1;
    int top2=n-1;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d",&a);
        
        if(a==1)
        {
            if(top1+1==top2)
            {
                printf("stack overflow");
                
            }
             scanf("%d",&b);
            top1++;
            arr[top1]=b;

        }
        else if(a==2)
        {
        if(top1+1==top2)
        {
            printf("stack overflow");
            
        }
         scanf("%d",&b);
        top2--;
        arr[top2]=b;

    }
    else if(a==3)
    {
        if(top1==-1)
        {
            printf("stack underflow");
        }
        printf("%d\n",arr[top1]);
        top1--;
    }
    else if(a==4)
    {
        if(top2==n-1)
        {
            printf("stack underflow");
        }
        printf("%d\n",arr[top2]);
        top2++;

    }
    else if(a==-1)
    {
        break;
    }
}
}