#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct infix
{
    char data;
    struct infix *next;
};
void decide(char x);
void push(char a);
void pop();
void popall();
void operation(char c,int curr);
int precedence(char e);
int leftassociative(char g);


struct infix *top=NULL;
int main()
{
    char str[100];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    for(int i=0;str[i]!='\0';i++)
    {
        decide(str[i]);
    }
    popall();
    return 0;
    
}
void decide(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
    {
        int currprecedence=precedence(x);
        operation(x,currprecedence);
    }
    else if(x==' ')
    {
        return;
    }
    else if(x=='(')
    {
        push(x);
    }
    else if(x==')')
    {
        pop();
    }
    else 
    {
        printf("%c ",x);
    }

}
void push(char a)
{
    struct infix *node=NULL;
    node=(struct infix*)malloc(sizeof(struct infix));
    if(node==NULL)
    {
        printf("memory allocation failed");
        return;
    }
    node->data=a;
    node->next=top;
    top=node;
}
void pop()
{
    if(top==NULL)
    {
        printf("List is empty");
    }
    while(top!=NULL && top->data!='(')
    {
    struct infix *temp=top;
    printf("%c ",temp->data);
     top=top->next;
    free(temp);
    }

    if(top!=NULL && top->data=='(')
    {
        struct infix *ptr=NULL;
        ptr=top;
        top=top->next;
        free(ptr);
    }
}
void popall()
{
    if(top==NULL)
    {
        return;
    }
    struct infix *ptr=NULL;
    ptr=top;
    while (ptr!=NULL)
    {
        
        printf("%c ",ptr->data);
        ptr=ptr->next;
    }
    
}
int precedence(char e)
{
    if(e=='+'||e=='-')
    {
        return 1;
    }
    else if(e=='*'||e=='/')
    {
        return 2;
    }
    else if(e=='^')
    {
        return 3;
    }

}
int isleftassociative(char g)
{
    if(g=='^')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void operation(char p,int curr)
{
    while(top!=NULL && top->data!='(' &&((precedence(top->data)>curr)||(precedence(top->data)==curr && isleftassociative(p))))
{
struct infix *temp=top;
printf("%c ",temp->data);
top=top->next;
free(temp);
}
push(p);
}