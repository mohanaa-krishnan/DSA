#include<stdio.h>
#define size 100
int arr[size];
int top=-1;
void push(int x);
void peek();
void display(int a);
void pop();
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        push(t);
    }
    display(n);
    peek();
    pop();
    display(n);
    return 0;
}
void push(int x)
{
    if(top==size-1)
    {
        printf("stack overflow");
        return;
    }
    top++;
    arr[top]=x;
}
void display(int a)
{
    if(top==-1)
    {
        printf("stack underflow");
        return;
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void pop()
{
    if(top==-1)
    {
        printf("stack underflow");
        return;
    }
    printf("%d\n",arr[top]);
    top--;
}
void peek()
{
    if(top==-1)
    {
        printf("stack underflow");
        return;
    }
    printf("%d\n",arr[top]);
}