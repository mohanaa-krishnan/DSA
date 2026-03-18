#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    char data;
    struct node *next;
};
struct node *top=NULL;
void push(char x);
void pop(char y);
void display();
int flag=0;
int main()
{
    char str[100];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    for(int i=0;str[i]!='\0';i++)
    {
if( str[i]=='('||str[i]=='{'||str[i]=='[')
{
    push(str[i]);
}
else if (str[i]==')'||str[i]=='}'||str[i]==']')
{
    pop(str[i]);
    }
}

    
display();
}

void push(char x)
{
    struct node *newnode=NULL;
    newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memory allocation failed");
        return;
    }
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}

void pop(char y)
{
    
    if(top==NULL)
    {
        printf("false");
        exit(1);
    }
    if(y==')' && top->data!='('||y=='}' && top->data!='{'||y==']' && top->data!='[')
    {
        printf("false");
        exit(1);
    }
   
    struct node *ptr=NULL;
    ptr=top;
    top=top->next;
    free(ptr);
    flag=1;
}


void display()
{
    if(top==NULL && flag==1)
    {
        printf("true");
        return;
    }
    else if ((top!=NULL||top==NULL) && flag==0)
    {
        printf("false");
  
}
}