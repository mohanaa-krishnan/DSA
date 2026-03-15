#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data[100];
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(char x[]);
void dequeue();
void display();
int main()
{
    int n;
    scanf("%d",&n);
    getchar();

    for(int i=0;i<n;i++)
    {
    char str[100];
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    if(strlen(str)==0)
    {
        i--;
        continue;
    }
    if(strncmp(str,"ENQUEUE ",8)==0)
    {
        enqueue(str + 8);
    }
    else if(strcmp(str,"DEQUEUE")==0)
    {
        dequeue();
    }
    else if(strcmp(str,"DISPLAY")==0)
    {
        display();
    }
    else{
        printf("Invalid command.");
    }
    }
    return 0;
}

void enqueue(char x[])
{
struct node *newnode=NULL;
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode==NULL)
{
    return;
}
strcpy(newnode->data,x);
newnode->next=NULL;
if(front==NULL)
{
    front=newnode;
    rear=newnode;
}
else
{
    rear->next=newnode;
    rear=newnode;
}
}

void dequeue()
{
    struct node *temp=NULL;
    if(front==NULL)
    {
        printf("Queue is empty.");
        return;
    }
    temp=front;
    front=front->next;
    printf("Processed Ticket: %s\n",temp->data);
    free(temp);
    if(front==NULL)
    {
        rear=NULL;
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
        printf("%s ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    
}