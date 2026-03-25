#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
};
int n;
struct node *insertion(int n);
void display(struct node *ptr);
struct node *deletion(int idx,struct node *curr,int a);
int main()
{
    //int n;
    scanf("%d",&n);
    struct node *head=insertion(n);
    int idx;
    
    scanf("%d",&idx);
    if(idx>0 && idx<=n)
    {
        idx=n-idx+1;
    struct node *newhead=deletion(idx,head,n);
    
    display(newhead);
    }
    else
    {
        display(head);
    }
    return 0;
}
void display(struct node *ptr)
{
    if(ptr==NULL)
    {
        printf("empty");
        return;
    }
    struct node *temp=ptr;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
struct node *insertion(int n)
{
    struct node *head=NULL;
        struct node *temp=NULL;
    struct node *newnode=NULL;
    for(int i=0;i<n;i++)
    {
        newnode=malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            exit(1);
        }
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

struct node *deletion(int idx,struct node *curr,int a)
{

    if(idx==1)
    {
        struct node *temp=curr;
        curr=curr->next;
        free(temp);
        return curr;
    }
    curr->next=deletion(idx-1,curr->next,a);
    return curr;
}