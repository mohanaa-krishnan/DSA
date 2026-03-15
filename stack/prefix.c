#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char value;
    struct  node *next;
    
};
struct node2
{
    char data;
    struct node2 *add;
};
void push(char x);
int precedencee(int k);
void operation(char t, int curr);
void push2(char p);
void pop();
struct node2 *front=NULL;
struct node *top=NULL;

char *reversestring(char str[],int n)
{
char *name=(char *)malloc((n+1)*sizeof(char));
for(int i=n-1;i>=0;i--)
{
    if(str[i]=='(')
    {
        str[i]=')';
    }
    else if(str[i]==')')
    {
        str[i]='(';
    }
    name[n-i-1]=str[i];
}
name[n]='\0';
return name;
}

void decide(char c)
{
    if(c==' ')
    {
        return;
    }
    else if(c=='+'||c=='*'||c=='-'||c=='/'||c=='^')
    {
        int precedence=precedencee(c);
        operation(c,precedence);
    }
    else if (c=='(')
    {
        push(c);
    }
    else if(c==')')
    {
        pop();
    }
    
    else
    {
        push2(c);
    }
}

void push(char x)
{
struct node *newnode=NULL;
newnode=malloc(sizeof(struct node));
if(newnode==NULL)
{
    printf("memory allocation failed");
    exit(1);
}
newnode->value=x;
newnode->next=top;
top=newnode;

}

void push2(char p)
{
    struct node2 *newnode=malloc(sizeof(struct node2));
    if(newnode==NULL)
    {
        printf("memory allocation failed");
        exit(1);
    }
    newnode->data=p;
    newnode->add=front;
    front=newnode;
}

void pop()
{
    struct node *ptr=NULL;
    if(top==NULL)
    {
        return;
    }
   
    while(top!=NULL && top->value!='(')
    {
         ptr=top;
         push2(ptr->value);
         top=top->next;
         free(ptr);
    }
    if(top!=NULL && top->value=='(')
    {
        struct node *temp=top;
        top=top->next;
        free(temp);
    }
}

void popall()
{
    
    if(top==NULL)
    {
        printf("stack is empty");
        exit(1);
    }
    
    while(top!=NULL)
    {
       struct node *temp=NULL;
       temp=top;
        push2(temp->value);
        top=top->next;
        free(temp);
    }
}

int precedencee(int k)
{
    if(k=='+'||k=='-')
    {
        return 1;
    }
    else if(k=='*'||k=='/')
    {
        return 2;
    }
    else if(k=='^')
    {
        return 3;

    }
    else
    {
        return 0;
    }
}

int isleftassociative(char y)
{
    if(y=='^')
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

void operation(char t,int curr)
{
    while(top!=NULL && top->value!='(' && ((precedencee(top->value)>curr)||(precedencee(top->value)==curr && !isleftassociative(t))))
    {
        struct node *temp=top;
        push2(temp->value);
        top=top->next;
        free(temp);
    }
    push(t);
}

void display()
{
    struct node2 *temp=NULL;
    if(front==NULL)
    {
        return;
    }
    temp=front;
    while(temp!=NULL)
    {
        printf("%c",temp->data);
        temp=temp->add;
    }
}

int main()
{
    char str[100];
    fgets(str,sizeof(str),stdin);
    
    str[strcspn(str,"\n")]='\0';
    int x=strlen(str);
    char *p=reversestring(str,x);
    //printf("%s",p);
    for(int i=0;p[i]!='\0';i++)
    {
        decide(p[i]);
    }
    popall();
    display();
        free(p);

return 0;

}