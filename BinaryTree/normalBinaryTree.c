#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *left;
    struct node *right;
};
void insertion(struct node *root);
struct node *nodecreation(int element);
void display(struct node *root,int level);
int main()
{
    int data;
    printf("enter the root value:\n");
    scanf("%d",&data);
    struct node *root;
    int level=0;
    root->value=data;
    root->left=NULL;
    root->right=NULL;
    insertion(root);
    display(root,level);
    return 0;

}

void insertion(struct node *root)
{
    int d;
    printf("do you want to insert left of %d:\n",root->value);
    scanf("%d",&d);
    if(d==1)
    {
        int val;
        printf("enter the value:");
        scanf("%d",&val);

        root->left=nodecreation(val);
        insertion(root->left);
    }
    int c;
    printf("do you want to insert right of %d:\n",root->value);
    scanf("%d",&c);
    if(c==1)
    {
        int val;
        printf("enter the value:");
        scanf("%d",&val);
        root->right=nodecreation(val);
        insertion(root->right);

    }

    
}

void display(struct node *root,int level)
{
    if(root==NULL)
    {
        return;
    }
    display(root->right,level+1);
    if(level!=0)
    {
        for(int i=0;i<level-1;i++)
    {
        printf("|  ");
    }
    printf("|----->%d\n",root->value);
    }
    else{
        printf("%d\n",root->value);
    }
    display(root->left,level+1);
}

struct node *nodecreation(int element)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->value=element;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}