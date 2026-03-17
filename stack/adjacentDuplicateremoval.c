#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{   
    char  data;
    struct node *next;
};
struct node *top=NULL;
void push(char n);
void pop(); 
void display();
void reverse();
int main()
{
    char str[100];
    fgets(str,100,stdin);
    str[strcspn(str, "\n")] = 0;
    for(int i=0;str[i]!='\0';i++)
    {
    if(top!=NULL && top->data==str[i])
    {
        pop();
        //continue;    for only one time occurance of characters
    }
    else{
        push(str[i]);
    }
    }
    reverse();
display();

    return 0;
}

void push(char n)
{
    //struct node *temp=NULL;
    struct node *newnode=NULL;
    newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memory allocation failed");
        return ;
    }
    newnode->data=n;
    newnode->next=top;
    top=newnode;
}

void pop()
{
    struct node *temp=NULL;
    if(top==NULL)
    {
        printf("Stack is empty");
        return;
    }
    temp=top;
    top=top->next;
    free(temp);
}

void display()
{
    struct node *ptr=NULL;
    if(top==NULL)
    {
        printf("Empty String");
        return;
    }
ptr=top;
while (ptr!=NULL)
{
    printf("%c",ptr->data);
    ptr=ptr->next;
}

}

void reverse()
{
    struct node *curr=top;
    struct node *prev=NULL;
    struct node *next=NULL;

    if(top==NULL)
    {
        return;
    }
    //struct node *first=top;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    top=prev;
}