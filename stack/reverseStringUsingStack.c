#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
  char s;
  struct node *next;
};

struct node *top=NULL;

void push(char x);
void pop();

int main()
{
  char str[100];
  int count;

  fgets(str,sizeof(str),stdin);
  str[strcspn(str,"\n")]='\0';

  count=strlen(str);

  for(int i=0;str[i]!='\0';i++)
  {
    push(str[i]);
  }

  pop();
 
 return 0; 
}

void push(char x)
{
  struct node *newnode=NULL;

  newnode=(struct node*)malloc(sizeof(struct node));

  if(newnode==NULL)
  {
    printf("memory allocation failed");
    return;
  }

  newnode->s=x;
  newnode->next=top;
  top=newnode;
}

void pop()
{
  struct node *temp=top;

  if(top==NULL)
  {
    return;
  }

  while(top!=NULL)
  {
    temp=top;
    printf("%c",top->s);
    top=top->next;
    free(temp);
  }
}