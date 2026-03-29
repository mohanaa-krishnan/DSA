#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *left;
    struct node *right;
};
struct node *nodecreation(int element);
struct node *insertion(int arr[],int start,int end);
void display(struct node *root,int level);
int main()
{
    int size;
    scanf("%d",&size);
    int arr[size];
    struct node *root=NULL;
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    int start=0;
    int end=size;
    int level =0;
    root=insertion(arr,start,end-1);
    display(root,level);
    return 0;

}

struct node *insertion(int arr[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=start +(end-start)/2;
    struct node *root=nodecreation(arr[mid]);

    root->left=insertion(arr,start,mid-1);
    root->right=insertion(arr,mid+1,end);

    return root;
}

struct node *nodecreation(int element)
{
struct node *newnode=malloc(sizeof(struct node));
newnode->value=element;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
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
        printf("----->%d\n",root->value);
    }
    else{
        printf("%d\n",root->value);
    }
    display(root->left,level+1);
}