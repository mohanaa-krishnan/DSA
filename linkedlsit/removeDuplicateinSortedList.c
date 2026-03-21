#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};


struct node *insertion(int n);
struct node *removeDuplicate(struct node *head);
void display();

int main() {
    int a;
    scanf("%d",&a);
    //insertion(a);
    display(removeDuplicate(insertion(a)));
    return 0;
}

struct node  *insertion(int n) {
    struct node *head=NULL;

    struct node *temp=NULL;
    struct node *newnode=NULL;
    for(int i=0;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("memory alloctation failed");
            return 0;
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
    return head;

}

void display(struct node *ptr)
{
    
    if(ptr==NULL)
    {
        printf("List is empty");
        return;
    }
   
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

struct node *removeDuplicate(struct node *head)
{
    struct node *curr=head;
    while(curr!=NULL && curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            curr->next=curr->next->next;
        }
        else{
            curr=curr->next;
        }

    }
    return head;
}