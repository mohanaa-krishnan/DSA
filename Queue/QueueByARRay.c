#include<string.h>
#include<stdio.h>
int n;
char name[50][20];
int front=-1;
int rear=-1;
void Enqueue(char x[]);
void Dequeue();
void Display();
int main()
{
    
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    getchar();
    char  str[100],command[20];
    for(int i=0;i<m;i++)
    {
        scanf("%s",command);
        if(strcmp(command,"ENQUEUE")==0)
        {
            scanf("%s",str);
            Enqueue(str);
        }
        else if(strcmp(command,"DEQUEUE")==0)
        {
            Dequeue();
        }
        else if(strcmp(command,"DISPLAY")==0)
        {
            Display();
        }
    }
}
void Enqueue(char x[])
{
 if(rear==n-1)
 {
    printf("Queue is full.Cannot add %s\n",x);
    return;
 }    
 if(front==-1)
 {
    front=0;
 }
 rear++;
 strcpy(name[rear],x);
}
void Dequeue()
{
    if(front==-1||front>rear)
    {
        printf("Served Customer: Queue is empty. No customer to serve.\n");
    return;
    }
    printf("Served Customer:%s\n",name[front]);
    front++;
}
void Display()
{
    if(front==-1||front>rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Current Queue:");
    int i=front;
    while(i<=rear)
    {
        printf("%s ",name[i]);
        i++;
    }
    printf("\n");
}