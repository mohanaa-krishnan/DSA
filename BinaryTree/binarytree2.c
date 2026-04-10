#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
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
struct node *find2(struct node *root,int val);
bool iscousins(struct node *root,int x,int y);

bool symmetric(struct node *root);
\
struct node *inorder(struct node *root);
struct node *preorder(struct node *root);
struct node *postorder(struct node *root);

int height(struct node *root,int *diameter);

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
  int value;
  scanf("%d",&value);

  struct node *Root=find2(root,value);

  if(Root!=NULL)
  {
    printf("%d\n",Root->data);
    if(Root->left!=NULL)
    {
        printf("%d",Root->left->data);

    }
    printf("%d",Root->data);
    if(Root->right!=NULL)
    {
        printf("%d",Root->right->data);
    }
    printf("\n");
    


  }
  struct node *ROOT=postorder(root);
  int diameter=0;
  int heightt=height(root,&diameter);
  printf("\n%d\n%d",heightt,diameter);
  return 0;

   //printf("%d",symmetric(root));
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
    
struct node *find2(struct node *root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }
     struct node *leftt=NULL;
     struct node *rightt=NULL;

    if(root->data==val)
    {
        return root;
    }
    if(val<root->data)
    {
       leftt=find2(root->left,val);
    }
    if(leftt!=NULL)
    {
        return leftt;
    }
    if(val>root->data)
    {
        rightt=find2(root->right,val);
    }
    if(rightt!=NULL)
    {
        return rightt;
    }
    return NULL;
    
}

struct node *inorder(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    struct node *l=inorder(root->left);
    if(l==NULL)
    {
        printf("%d",root->data);
    }
    return inorder(root->right);
}

struct node *preorder(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
     printf("%d",root->data);
    struct node *l=preorder(root->left);
    
    if(l==NULL)
    
        {
           
        return preorder(root->right);
    }
    
    return NULL;
}

struct node *postorder(struct node *root)
{
    if(root!=NULL)
    {
        
    
    struct node *l=postorder(root->left);
    struct node *r=postorder(root->right);
if(l==NULL||r==NULL)
{
printf("%d",root->data);
}    
}
    
    
    return NULL;
}

int height(struct node *root,int *diameter)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=height(root->left,diameter);
    int r=height(root->right,diameter);

    int dia=l+r+1;
    *diameter=MAX(*diameter,dia);

    return MAX(l,r)+1;

}