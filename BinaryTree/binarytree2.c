#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

int count=0;
struct node *insertion(struct node *root,int value);
struct node *nodecreation(int value);
int countt(struct node *root);

bool issibiling(struct node *root,struct node *x,struct node *y);
int level(struct node *root,struct node *x,int levell);
struct node *find(struct node *root,int val);
bool iscousins(struct node *root,int x,int y);

bool symmetric(struct node *root);


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
    
   /*
    int value;
    int x,y;
    scanf("%d",&value);
    scanf("%d",&x);
    scanf("%d",&y);
    int levell=level(root,find(root,value),0);
    int nodes=countt(root);
   printf("%d\n %d\n",nodes,levell);
   printf("%d\n",issibiling(root,find(root,x),find(root,y)));
   printf("%d",iscousins(root,x,y));
   */

   printf("%d",symmetric(root));
    }

struct node *nodecreation(int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    count++;
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

//COUNT NUMBER OF NODES BY RECURSION

int countt(struct node *root)
{
    if(root==NULL)
    {
        
        return 0;
    }
    
   int left=countt(root->left);
       int right=countt(root->right);
    return left+right+1;

}

//NODES ARE SIBILINGS OR COUSINS

bool issibiling(struct node *root,struct node *x,struct node *y)
{
    if(root==NULL)
    {
        return false;
    }
 return (root->left==x && root->right==y)||(root->left==y && root->right==x)||issibiling(root->left,x,y) || issibiling(root->right,x,y);
}

struct node *find(struct node *root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==val)
    {
        return root;
    }
    struct node *temp=find(root->left,val);
    if(temp!=NULL)
    {
        return temp;
    }
    return find(root->right,val);
}

int level(struct node *root,struct node *x,int levell)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root==x)
    {
        return levell;
    }
    int lvl=level(root->left,x,levell+1);
    if(lvl!=0)
    {
        return lvl;
    }
    return level(root->right,x,levell+1);
}

bool iscousins(struct node *root,int x,int y)
{

    if(root==NULL)
    {
        return false;
    }
    struct node *xx=find(root,x);
    struct node *yy=find(root,y);

    if (level(root,xx,0)==level(root,yy,0) &&!issibiling(root,xx,yy))
    {
        return true;
    }
    
    return false;

}


//  SYMMETRIC TREE FINDING

bool symmetric(struct node* root) {
    
   if(root==NULL)
   {
    
    return false;
   }
   int flag=1;
   
   
   struct node *queue[10000];
   int front=0,rear=0;
   queue[rear++]=root;
   while(front<rear)
   {
    int size=rear-front;
   int *arr=malloc(sizeof(int)*size);
    for(int i=0;i<size;i++)
    {
        
        struct node *current=queue[front++];
        if(current==NULL)
        {
            arr[i]=-99;
            continue;
        }
        else
        {
        arr[i]=current->data;
        }
        if(current->right!=NULL && current->left!=NULL)
        {
            queue[rear++]=current->left;
            queue[rear++]=current->right;
        }
        else if(current->left!=NULL && current->right==NULL)
        {
            queue[rear++]=current->left;
            queue[rear++]=NULL;
        }
        
        else if(current->right!=NULL && current->left==NULL)
        {
            queue[rear++]=NULL;
            queue[rear++]=current->right;
            
        }
        else if(current->right==NULL && current->left==NULL)
        {
            queue[rear++]=NULL;
            queue[rear++]=NULL;
        }
    }
    int l=0;
    int r=size-1;
    while(l<r)
    {
        if(arr[l]!=arr[r])
        {
            flag=0;
            break;
        }
        l++;
        r--;
    }
}
    if(flag)
    {
        return true;
    }

   
   return false;

}
    
