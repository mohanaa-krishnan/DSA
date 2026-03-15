#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

struct node2 
{
    int d;
    struct node2 *add;
};
void push(int n);
void push2(int x);
void PushToStack();
void PushToQueue();
void display();
struct node2 *top=NULL; 



int main()
{
    int n;
    scanf("%d",&n);
    push(n);
    PushToStack();
    PushToQueue();
    display();
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

void PushToStack()
{
    
    
    if(front==NULL)
    {
        printf("Queue is empty");
        return;
    }
     struct node *curr=front;
    while(curr!=NULL)
    {
        push2(curr->data);
        curr=curr->next;
        
    }
}

void push2(int x)
{
    struct node2 *temp=NULL;
    temp=malloc(sizeof(struct node2));
    if(temp==NULL)
    {
        printf("memory allocation failed");
        return;
    }
    temp->d=x;
    temp->add=top;
    top=temp;

}

void PushToQueue()
{
   
    if(top==NULL && front==NULL)
    {
        printf("empty");
        return;
    }
    struct node *queue=NULL;
    queue=front;
    struct node2 *ptr=NULL;
        ptr=top;
    while(ptr!=NULL && queue!=NULL)
    {
        
        queue->data=ptr->d;
        queue=queue->next;
        ptr=ptr->add;
        
    }
    

}


void display()
{
    if(front==NULL)
    {
        printf("Queue is empty");
        return;
    }
    struct node *ptr=NULL;
    ptr=front;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    
}