#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node1
{
    int data;
    struct node1 *next;
};
struct node1 *front1=NULL;
struct node1 *rear1=NULL;

struct node2
{
    int value;
    struct node2 *add;
};
struct node2 *front2=NULL;
struct node2 *rear2=NULL;

void push2(int x);
void push1(int y);
void move1();
void move2();
void pop();
void top();
void empty();

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    int b;
    char  str[100],command[20];
    for(int i=0;i<n;i++)
    {
        scanf("%s",command);
        if(strcmp(command,"push")==0)
        {
            scanf("%d",&b);
            printf("Pushed: %d\n",b);
             move1();
            push1(b);
            move2();
        }
        else if(strcmp(command,"pop")==0)
        {
            pop();
        }
        else if(strcmp(command,"top")==0)
        {
            top();
        }
        else if(strcmp(command,"empty")==0)
        {
            empty();
        }
    }
}
void push1(int y)
{
    struct node1 *newnode=NULL;
    newnode=malloc(sizeof(struct node1));
    newnode->data=y;
    newnode->next=NULL;
    if(front1==NULL)
    {
        front1=newnode;
        rear1=newnode;
    }
    else
    {
    rear1->next=newnode;
    rear1=newnode;

}}

void push2(int x)
{
    struct node2 *newnode=NULL;
    newnode=malloc(sizeof(struct node2));
     newnode->value=x;
    newnode->add=NULL;
    if(front2==NULL)
    {
        front2=newnode;
        rear2=newnode;
    }
    else
    {
    rear2->add=newnode;
    rear2=newnode;
}
}

void move1()
{
    if(front1==NULL)
    {
        return;
    }
    while(front1!=NULL)
    {
        struct node1 *temp=front1;
        push2(temp->data);
        front1=front1->next;
        free(temp);
    }
    if(front1==NULL)
    {
        rear1=NULL;
    }

}

void move2()
{
    if(front2==NULL)
    {
        return;

    }
    while(front2!=NULL)
    {
        struct node2 *temp=front2;
        push1(temp->value);
        front2=front2->add;
        free(temp);
    }
    if(front2==NULL)
    {
        rear2=NULL;
    }
}

void pop()
{
    if(front1==NULL)
    {
        printf("empty");
        return;
    }
    struct node1 *temp=front1;
    printf("Popped: %d\n",temp->data);
    front1=front1->next;
    free(temp);
}

void top()
{
    if(front1==NULL)
    {
        printf("empty");
        return;
    }
    printf("Top version: %d\n",front1->data);
}

void empty()
{
    if(front1==NULL)
    {
        printf("true\n");
        return;
    }
    else
    {
        printf("false\n");
    }

}