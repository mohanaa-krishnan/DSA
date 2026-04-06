#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int start;
    int end;
    struct node *left;
    struct node *right;
};
struct node *update(struct node *root,int index,int value);
struct node *create(int arr[]);
struct node *insertion(int left,int right,int arr[]);
int query (struct node *root,int qstart,int qend);

void display(struct node *root);
int main()
{
    int arr[]={2,3,5,6,4,9,8,7};
    int q1,q2;
    scanf("%d %d",&q1,&q2);


struct node *newroot=create(arr);
display(newroot);
printf("%d",query(newroot,q1,q2));
//display(newroot);
return 0;
}

struct node *create(int arr[])
{
    int size=7;
    return insertion(0,size,arr);
}
struct node *insertion(int left,int right,int arr[])
{
if(left==right)
{
    struct node *root=malloc(sizeof(struct node));
    root->start=left;
    root->end=right;
    root->data=arr[left];
    return root;
}

int mid =left+(right-left)/2;
struct node *newnode=malloc(sizeof(struct node));
newnode->start = left;
newnode->end = right;
newnode->left=insertion(left,mid,arr);
newnode->right=insertion(mid+1,right,arr);

newnode->data=newnode->left->data+newnode->right->data;

return newnode;
}


void display(struct node *root)
{
    if(root->left!=NULL)
    {
        printf("interval[%d,%d],Data[%d] ",root->left->start,root->left->end,root->left->data);
    }
    else
    {
        printf("No left child ");
    }
            printf("interval[%d,%d],Data[%d] ",root->start,root->end,root->data);
    if(root->right!=NULL)
    {
                printf("interval[%d,%d],Data[%d]\n ",root->right->start,root->right->end,root->right->data);

    }
    else{
        printf("No right child\n ");
    }
    if(root->left!=NULL)
    {
        display(root->left);
    }
    if(root->right!=NULL)
    {
        display(root->right);
    }

}

struct node *update(struct node *root,int index,int value)
{
    if(index<root->start||index>root->end)
    {
        return root;
    }
    if(index==root->start&&index==root->end)
    {
        root->data=value;
        return root;
    }
    root->left=update(root->left,index,value);
    root->right=update(root->right,index,value);
    root->data=root->left->data+root->right->data;
    return root;
}

int query (struct node *root,int qstart,int qend)
{
    if(root->start>=qstart && root->end<=qend)
    {
        return root->data;
    }
    else if(root->start>qend || root->end<qstart)
    {
        return 0;
    }
    else{
        return query(root->left,qstart,qend) + query(root->right,qstart,qend);
    }
}