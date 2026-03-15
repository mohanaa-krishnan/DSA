#include<stdlib.h>

#include<stdio.h>

struct node
{

        int data;

            struct node *next;

};



struct node *head=NULL;

void insertion(int n);

void reversal(int a);

void display();

int main()

{

        int n;

            scanf("%d",&n);

                int b;

                    scanf("%d",&b);

                        insertion(n);

                            reversal(b);

                                display();

                                    return 0;

}

void insertion(int n)

{

        struct node *temp=NULL;

            struct node *newnode=NULL;

                for(int i=0;i<n;i++)

                    {

                            newnode=malloc(sizeof(struct node));

                                if(newnode==NULL)

                                    {

                                                printf("memory allocation failed");

                                                        return ;

                                    }

                                        scanf("%d",&newnode->data);

                                            newnode->next=NULL;

                                                if(head==NULL)

                                                    {

                                                                head=newnode;

                                                                        temp=newnode;

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

                                                                                printf("list is empty");

                                                                                        return;

                                                                    }

                                                                        ptr=head;

                                                                            

                                                                            while(ptr!=NULL)

                                                                                {

                                                                                            printf("%d ",ptr->data);

                                                                                                    

                                                                                                    ptr=ptr->next;

                                                                                }

                                                                            }



                                                                            void reversal(int a)

                                                                            {

                                                                                    if(a>0)

                                                                                        {

                                                                                                struct node *curr=head;

                                                                                                    struct node *prev=NULL;

                                                                                                        struct node *next=NULL;

                                                                                                            

                                                                                                            struct node *first=head;

                                                                                                                for(int i=0;i<a && curr!=NULL;i++)

                                                                                                                    {

                                                                                                                                next=curr->next;

                                                                                                                                        curr->next=prev;

                                                                                                                                                prev=curr;

                                                                                                                                                        curr=next;

                                                                                                                    }

                                                                                                                        head=prev;

                                                                                                                            first->next=curr;

                                                                                                                }
                                                                                                                    }
