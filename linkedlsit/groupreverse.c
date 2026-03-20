#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;

};
int a;
struct node *insertion(int n);
struct node *groupreverse(struct node *head,int k);
void display(struct node *ptr);
int main()
{

    scanf("%d",&a);
    if(a<1)
    {
        printf("invalid size\n");
        return 0;
    }
    
    struct node *head=insertion(a);
    int k;
    scanf("%d",&k);
    head=groupreverse(head,k);
    display(head);
    return 0;
}
struct node *insertion(int n)
{
    struct node *head=NULL;
       struct node *newnode=NULL;
          struct node *temp=NULL;
    for(int i=0;i<n;i++)
    {
        newnode=malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }

    }
    return head;
}

struct node  *groupreverse(struct node *head,int k)
{
if(k<1 || k>a)
{
    return head;
}
struct node *curr=head;
struct node *prev=NULL;
struct node *next=NULL;
int count=0;
while(curr!=NULL && count<k)
{
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    count++;
}
if(next!=NULL)
{
    head->next=groupreverse(curr,k);
}
return prev;
}

void display(struct node *ptr)
{
    if(ptr==NULL)
    {
        printf("List is empty");
        exit(1);
    }
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }

}