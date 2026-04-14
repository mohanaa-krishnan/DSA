#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
struct node
{
    int value;
    int height;
    struct node *left;
    struct node *right;
};
struct node *rotate(struct node *root);
struct node *rightrotate(struct node *root);
struct node *leftrotate(struct node *root);
int heightofnode(struct node *root);
int balanced(struct node *root);
struct node *nodecreation(int data);

struct node *insertion(int data,struct node *root);
void display(struct node *root,int level,char string[]);
int main()
{
int size;
scanf("%d",&size);
int arr[size];
struct node *root=NULL;
for(int i=1;i<=size;i++)
{
    arr[i]=i;
    root=insertion(arr[i],root);
}
//printf("%d\n",root->height);
display(root,0,"root node:");

return 0;
}

struct node *insertion(int data,struct node *root)
{
    if(root==NULL)
    {
        root=nodecreation(data);
        return root;
    }
    if(data<root->value)
    {
        root->left=insertion(data,root->left);
    }
    if(data>root->value)
    {
        root->right=insertion(data,root->right);
    }
    root->height=MAX(heightofnode(root->left),heightofnode(root->right))+1;
    return rotate(root);

}

struct node *nodecreation(int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->value=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=0;
    return newnode;

}

void display(struct node *root,int level,char string[])
{
    if(root==NULL)
    {
        return;
    }
    if(level!=0)
    {
        for(int i=0;i<level;i++)
        {
            printf("|  ");
        }
        printf("|---->%s%d\n",string,root->value);
    }
    else
    {
        printf("%s%d\n",string,root->value);
    }
    char leftstr[50]="Left child:";
    char rightstr[50]="Right child:";
    
    display(root->left,level+1,leftstr);
    display(root->right,level+1,rightstr);
    
}
int heightofnode(struct node *root)
{
    if(root==NULL)
    {
        return -1;
    }
    return root->height;
}

int balanced(struct node *root)
{
    if(root==NULL)
    {
        return 1;
    }
    return (abs(heightofnode(root->left)-heightofnode(root->right)<=1)&&(balanced(root->left)&&balanced(root->right)));

}

struct node *rotate(struct node *root)
{
    if(heightofnode(root->left)-heightofnode(root->right)>1)//left heavy
    {
        if((heightofnode(root->left->left)-heightofnode(root->left->right))>0)//left-left case
        {
            return rightrotate(root);
        }
                if((heightofnode(root->left->left)-heightofnode(root->left->right))<0)//left right case
                {
                    root->left=leftrotate(root->left);
                    return rightrotate(root);
                }
        
    }

    if(heightofnode(root->left)-heightofnode(root->right)<-1)//right heavy
    {
        if((heightofnode(root->right->right)-heightofnode(root->right->left))>0)//right-right case
        {
            return leftrotate(root);
        }
                if((heightofnode(root->right->right)-heightofnode(root->right->left))<0)//right left case
                {
                    root->right=rightrotate(root->right);
                    return leftrotate(root);
                }
        
    }

    return root;
}

struct node *rightrotate(struct node *root)
{
    struct node *newroot=root->left;
    struct node* newnode=newroot->right;
    newroot->right=root;
    root->left=newnode;

    root->height=MAX(heightofnode(root->left),heightofnode(root->right))+1;
    newroot->height=MAX(heightofnode(newroot->left),heightofnode(newroot->right))+1;

    return newroot;
}


struct node *leftrotate(struct node *root)
{
    struct node *newroot=root->right;
    struct node* newnode=newroot->left;
    newroot->left=root;
    root->right=newnode;

    root->height=MAX(heightofnode(root->left),heightofnode(root->right))+1;
    newroot->height=MAX(heightofnode(newroot->left),heightofnode(newroot->right))+1;

    return newroot;
}