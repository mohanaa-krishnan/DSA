#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void push(int n);
void reverse(int y);
void display();
int n;
int main()
{
    
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    if(n>=1)
    {
    push(n);
    display();
    reverse(m);
    display();
    }
    return 0;
}

void push(int n)
{

for(int i=0;i<n;i++)
{
    struct node *newnode=NULL;
newnode=malloc(sizeof(struct node));
if(newnode==NULL)
{
    printf("memory allocation failed");
    exit(1);
}
scanf("%d",&newnode->data);
newnode->next=NULL;
if(front==NULL)
{
    front=newnode;
    rear=newnode;
}
else{
    rear->next=newnode;
    rear=newnode;
}
}   
}


void reverse(int y)
{
    if(y>0 && y<n)
    {
    struct node *curr=front;
    struct node *prev=NULL;
    struct node *next=NULL;
    struct node *first=front;
    //rear=front;
    for(int i=0;i<y && curr!=NULL;i++)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    front=prev;
    first->next=curr;
}
}
void display()
{
    struct node *ptr=NULL;
    if(front== NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    ptr=front;
    printf("Current Queue: ");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    
}
