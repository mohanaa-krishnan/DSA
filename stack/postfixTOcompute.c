#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct compute
{
    int value;
    struct compute *next;
};
struct compute *top=NULL;
void push(int a);
void operation(char *op);
int pop();
void display();
int main()
{
 char str[100];
 fgets(str,sizeof(str),stdin);
 str[strcspn(str,"\n")]='\0';
 char *token=strtok(str," ");
 while(token!=NULL)
 {
    if(strcmp(token,"+")==0||strcmp(token,"-")==0||strcmp(token,"*")==0||strcmp(token,"/")==0)
    {
        operation(token);
    }
    else 
    {
        push(atoi(token));
    }
    token=strtok(NULL," ");
 }
 //display();
 printf("%d",pop());
 return 0;
}
void push(int a)
{
    struct compute *newnode=NULL;
    newnode=malloc(sizeof(struct compute));
    if(newnode==NULL)
    {
        printf("memory allocation failed");
        exit(1);
    }
    newnode->value=a;
    newnode->next=top;
    top=newnode;   
}
void operation(char *op)
{
    int b=pop();
    int a=pop();
    if(strcmp(op,"+")==0)
    {
        push(a+b);
    }
    else if(strcmp(op,"-")==0)
    {
        push(a-b);
    }
    else if(strcmp(op,"*")==0)
    {
        push(a*b);
    }
    else if(strcmp(op,"/")==0)
    {
        if(b==0)
        {
            printf("division by zero error");
            exit(1);
        }
        push(a/b);
    }
}
int  pop()
{
 struct compute *temp=NULL;
 if(top==NULL)
 {
    printf("stack is empty");
    return 1;
 }
 temp=top;
 int curr=temp->value;
 top=top->next;
 free(temp);
 return curr;
}
void display()
{
    if(top!=NULL)
    {
        printf("%d \n",top->value);
    }
}