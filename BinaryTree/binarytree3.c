#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

struct node{
    int data;
    struct node *left;
    struct node *right;
};


struct node *insertion(struct node *root,int value);
struct node *nodecreation(int value);


struct node *invert(struct node *root);
int minDepth(struct node *root);
void display(struct node *root);

void display4(struct node *root,int level);

struct node *trimming(struct node *root,int x,int y);
struct node *childcheck(struct node *root,int x,int y);

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
    int x=3;
    int y=4;
    display4(root,0);
    printf("\n");
    root=trimming(root,x,y);
    display4(root,0);
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
    if(value!=-9999)
    {
    if(value<root->data)
    {
        root->left=insertion(root->left,value);
    }
    if(value>root->data)
    {
        root->right=insertion(root->right,value);
    }
}
    return root;
}

void display(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    struct node *Queue[1000];
    int front=0,rear=0;
    Queue[rear++]=root;
    while(front<rear)
    {
        int size=rear-front;
        
        for(int i=0;i<size;i++)
        {
            struct node *current=Queue[front++];
           
            printf("%d ",current->data);
            if(current->left!=NULL)
            {
                Queue[rear++]=current->left;
            }
            if(current->right!=NULL)
            {
                Queue[rear++]=current->right;
            }
        }
    }
}

//INVERT THE TREE 


struct node *invert(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    struct node *l=invert(root->left);
    struct node *r=invert(root->right);

    root->left=r;
    root->right=l;

    return root;
}



//MINIMUM DEPTH OF NODE (SMALLEST PATH TO LEAF NODE)

int minDepth(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left!=NULL&&root->right==NULL)
    {
        return minDepth(root->left)+1;
    }
    if(root->left==NULL&&root->right!=NULL)
    {
        return minDepth(root->right)+1;
    }
    int l=minDepth(root->left);
    int r=minDepth(root->right);

    return MIN(l,r)+1;
}

//BINARY TREE TO LINKED LIST(SKEWED TREE)FLATTEN TREE

void linkedlist(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    struct node *current=root;
    while(current!=NULL)
    {
        
        if(current->left!=NULL)
        {
            struct node *temp=current;
            while(temp->right!=NULL)
            {
                temp=temp->right;
            }
            temp->right=current->right;
            current->right=current->left;
            current->left=NULL;

        }
        current=current->right;
    }
}


//TRIMMING A TREE

struct node *trimming(struct node *root,int x,int y)
{
    if(root==NULL)
    {
        return root;
    }
    struct node *l=trimming(root->left,x,y);
    struct node *r=trimming(root->right,x,y);
    if(root->data<x)
    {
        if(root->right!=NULL)
        {
        return r;
    }}
     if(root->data>y)
     {
        return l;
     }
    
    root->left=l;
    root->right=r;
    return root;
}

//JUST DISPLAY FUNCTION FOR UNDERSTANDING

void display4(struct node *root,int level)
{
    if(root==NULL)
    {
       
        return;
    }
    display4(root->right,level+1);
    if(level!=0)
    {
        for(int i=0;i<level-1;i++)
        {
            printf("|  ");
        }
        printf("|----->%d\n",root->data);
    }
    else{
        printf("%d\n",root->data);
    }
    display4(root->left,level+1);
}

