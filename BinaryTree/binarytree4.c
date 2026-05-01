#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>


struct node{
    int data,index;
    struct node *left;
    struct node *right;
};

struct node2{
    struct node  *element;
    struct node2 *next;
};

struct node2 *front=NULL;
struct node2 *rear=NULL;

struct node  *display2(struct node *root,int target);
void inordersuccessor(struct node *root,int target,struct node *successor);
void enqueue(struct node *value);
struct node *dequeue();

struct node *insertion(struct node *root,int value);
struct node *nodecreation(int value);
void display(struct node *root);

bool isValidBST(struct node* root);
bool isvalid(struct node *root,long low,long high);

struct node *kelemnt(struct node *root,int target);
struct node *inorderindex(struct node *root);

int p=1;
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
    struct node *temp=root;
    root=inorderindex(temp);
   // display(root);
  /*
    int target;
   scanf("%d",&target);
   inordersuccessor(root,target,NULL);
   root=display2(root,target);
   if(root==NULL)
   {
    printf("NO successor");
   }
else{
  printf("%d",root->data);
}
  */
int k;
scanf("%d",&k);
root=kelemnt(temp,k);
printf("%d",root->data);

return 0;
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
           
            printf("%d %d ",current->data,current->index);
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


//VALID BST

 bool isvalid(struct node *root,long low,long high)
 {
    if(root==NULL)
    {
        return true;
    }
    if(root->left==NULL &&root->right==NULL)
    {
        return root->data>low&&root->data<high;
    }
    if(root->left==NULL&&root->right!=NULL)
    {
        return root->data>low&&root->data<high&&isvalid(root->right,root->data,high);
    }
    if(root->right==NULL&&root->left!=NULL)
    {
        return root->data>low &&root->data<high&&isvalid(root->left,low,root->data);
    }
    if(low!=INT_MIN&&root->data<=low)
    {
        return false;
    }
    if(high!=INT_MAX&&root->data>=high)
    {
        return false;
    }

bool leftnode=isvalid(root->left,low,root->data);
bool rightnode=isvalid(root->right,root->data,high);

    return leftnode&&rightnode;
 }
bool isValidBST(struct node* root) {
   return isvalid(root,LONG_MIN,LONG_MAX);
}


struct node  *display2(struct node *root,int target)
{
    if (root == NULL)
        return root;
   

   struct node *l=display2(root->left,target);
   if(l==NULL)
   {
enqueue(root);
   }
   if(front->element->data==target)
   
   {
    if(front!=NULL&&front->next!=NULL)
    {
        return front->next->element;
        exit(1);
    }
    
   }
   else{
    front=front->next;
   }
    
    
    
    return display2(root->right,target);
}

void inordersuccessor(struct node *root,int target,struct node *successor)
{
    if(root==NULL)
    {
        return;
    }
    if(target<root->data)
    {
        inordersuccessor(root->left,target,root);

    }
    if(target>root->data)
    {
        inordersuccessor(root->right,target,successor);
    }
    if(target==root->data)
    {
        if(root->right!=NULL)
        {
            struct node *temp=root->right;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            successor=temp;
        }
        if(successor==NULL)
        {
            printf("NULL");
        }
        else
        {
        printf("%d",successor->data);
                }
                        exit(1);
    }
}

void enqueue(struct node *value)
{
    if(value==NULL)
    {
        return;
    }
   
    //printf("%d",value->data);
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

// K TH SMALLEST ELEMENT

struct node *kelemnt(struct node *root,int target)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->index==target)
    {
        return root;
    }
    if(target<root->index)
    {
      root= kelemnt(root->left,target);
    }
    if(target>root->index)
    {
        root=kelemnt(root->right,target);
    }
    return root;
}

struct node *inorderindex(struct node *root)
{
if(root==NULL)
{
    return root;
}
struct node *l=inorderindex(root->left);
if(l==NULL)
{
root->index=p++;
}



return  inorderindex(root->right);
}
