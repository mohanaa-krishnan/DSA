#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node2{
    struct node  *element;
    struct node2 *next;
};

struct node2 *front=NULL;
struct node2 *rear=NULL;

struct node *nodecreation(int value);
struct node *insertion(struct node *root,int value);
void display(struct node *root);
void enqueue(struct node *value);
struct node *dequeue(void);

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    struct node *root=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        root=insertion(root,arr[i]);
    }
    display(root);
}

struct node *nodecreation(int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *insertion(struct node *root,int value)
{
    if(root==NULL)
    {
        root=nodecreation(value);
        return root;
    }
    if(value<root->data)
    {
        root->left=insertion(root->left,value);
    }
    if(value>root->data)
    {
        root->right=insertion(root->right,value);
    }
    return root;
}

void display(struct node *root)
{
    if (root == NULL)
        return;

    enqueue(root);
    while (front != NULL)
    {
        struct node *current = dequeue();
        if (current == NULL)
            break;

        printf("%d ", current->data);
        if (current->left != NULL)
            enqueue(current->left);
        if (current->right != NULL)
            enqueue(current->right);
    }
}

void enqueue(struct node *value)
{
    struct node2 *newnode=NULL;
    newnode=malloc(sizeof(struct node2));
    newnode->element=value;
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

struct node *dequeue()
{
    if (front == NULL)
    {
        return NULL;
    }

    struct node2 *temp = front;
    struct node *element = temp->element;
    front = front->next;
    free(temp);

    if (front == NULL)
    {
        rear = NULL;
    }

    return element;
}