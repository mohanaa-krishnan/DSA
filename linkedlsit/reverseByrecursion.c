#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
};
struct node *insertion(int n);
void display(struct node *ptr);
struct node *reverse(struct node *head);
int main()
{
    int n;
    scanf("%d",&n);
    struct node *head=insertion(n);
    head=reverse(head);
    display(head);
    return 0;
}

struct node *insertion(int n)
{
        struct node *head=NULL;
            struct node *temp=NULL;
        struct node *newnode=NULL;
        for(int i=0;i<n;i++)
        {
            newnode=malloc(sizeof(struct node));
            if(newnode==NULL)
            {
                exit(1);
            }
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            if(head==NULL)
            {
                head=temp=newnode;
            }
            else{
                temp->next=newnode;
                temp=newnode;
            }
        }
    return head;
    }

    void display(struct node *ptr)
    {
        if(ptr==NULL)
        {
            printf("List is empty");
            exit(1);
        }
        struct node *temp=NULL;
        temp=ptr;
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }

    }

struct node *reverse(struct node *head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    struct node *newhead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}