#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *head=NULL;

void insertion(int n);
void display();

int main() {
    int a;
    scanf("%d",&a);
    insertion(a);
    display();
    return 0;
}

void insertion(int n) {
    struct node *temp=NULL;
    struct node *newnode=NULL;
    for(int i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("memory alloctation failed");
            return;
        }
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    } 

}

void display()
{
    struct node *ptr=NULL;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
