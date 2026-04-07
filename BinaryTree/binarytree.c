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

int count=0;
int nodes=0;
struct node2 *front=NULL;
struct node2 *rear=NULL;

struct node *nodecreation(int value);
struct node *insertion(struct node *root,int value);
void display(struct node *root);
void enqueue(struct node *value);
struct node *dequeue(void);
int  **display2(struct node *root,int *returnsize,int **columnsize);
double *AVGG(struct node *root,int *returnsize);
int succesornode(struct node *root,int target);
void reverse2(int *rev,int sizee);
int **reverse1(int **rev,int sizee);
int **display3(struct node *root,int *returnsize,int **columnsize);


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
    int returnsize=0;
    int *columnsize=NULL;
    int **result=display3(root,&returnsize,&columnsize);
    //double *avgg=AVGG(root,&returnsize);
    
    for (int i=0;i<returnsize;i++)
    {
        for(int j=0;j<columnsize[i];j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
   // display(root);


/*
for(int i=0;i<returnsize;i++)
{
    printf("%lf\n",avgg[i]);
}
int target;
scanf("%d",&target);
int value=succesornode(root,target);
printf("%d",value);
*/
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
    count++;
    nodes++;
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
    count--;

    return element;
}


//LEVEL ORDER DISPLAY


int **display2(struct node *root,int *returnsize,int **columnsize)
{
    if(root==NULL)
    {
        *returnsize=0;
        *columnsize=NULL;
        return NULL;
    }
    int **result=NULL;
    *returnsize=0;
    *columnsize=NULL;
    enqueue(root);
    while(front!=NULL)
    {
        int size=count;
        int *arr=malloc(size*sizeof(int));
        for(int i=0;i<size;i++)
        {
            struct node *current=dequeue();
            if(*returnsize%2==0)
            {

            
            arr[i]=current->data;
            }
            if(*returnsize%2!=0)
            {

                arr[size-i-1]=current->data;
            }
            if(current->left!=NULL)
            {
                enqueue(current->left);
            }
            if(current->right!=NULL)
            {
                enqueue(current->right);
            }
        }
        result=realloc(result,(*returnsize+1)*sizeof(int*));
        *columnsize=realloc(*columnsize,(*returnsize+1)*sizeof(int));
        result[*returnsize]=arr;
        (*columnsize)[*returnsize]=size;
        (*returnsize)++;

    }
    return result;

}

//AVG OF EACH LEVEL

double *AVGG(struct node *root,int *returnsize)
{
   if(root==NULL)
   {
    *returnsize= 0;
    return NULL;
   }
   
   *returnsize=0;
   struct node *queue[10000];
   int front=0,rear=0;
   double *arr=malloc(sizeof(double)*10000);
   queue[rear++]=root;
   while(front<rear)
   {
    int size=rear-front;
    double sum=0;
    for(int i=0;i<size;i++)
    {
        struct node *current=queue[front++];
        sum+=current->data;
        if(current->left!=NULL)
        {
            queue[rear++]=current->left;
        }
        if(current->right!=NULL)
        {
            queue[rear++]=current->right;
        }
    }
    arr[(*returnsize)++]=sum/size;


   }
   return arr;

}

//SUCCESOR NODE 


int succesornode(struct node *root,int target)
{
   if(root==NULL)
   {
    
    return -1;
   }
   
   
   struct node *queue[10000];
   int front=0,rear=0;
   
   queue[rear++]=root;
   while(front<rear)
   {
    int size=rear-front;
  
    for(int i=0;i<size;i++)
    {
        struct node *current=queue[front++];
      
        if(current->left!=NULL)
        {
            queue[rear++]=current->left;
        }
        if(current->right!=NULL)
        {
            queue[rear++]=current->right;
        }
        if(current->data==target)
        {
            struct node *succesor=queue[front];
            if(succesor==NULL)
            {
                return -1;
            }
            int value=succesor->data;
            return value;
        }
    }
   


   }
   return -1;

}

//LEVEL ORDER DISPLAY BOTTOM TO TOP


int **display3(struct node *root,int *returnsize,int **columnsize)
{
    if(root==NULL)
    {
        *returnsize=0;
        *columnsize=NULL;
        return NULL;
    }
    int **result=NULL;
    *returnsize=0;
    *columnsize=NULL;
    enqueue(root);
    while(front!=NULL)
    {
        int size=count;
        int *arr=malloc(size*sizeof(int));
        for(int i=0;i<size;i++)
        {
            struct node *current=dequeue();
            if(*returnsize%2==0)
            {

            
            arr[i]=current->data;
            }
            if(*returnsize%2!=0)
            {

                arr[size-i-1]=current->data;
            }
            if(current->left!=NULL)
            {
                enqueue(current->left);
            }
            if(current->right!=NULL)
            {
                enqueue(current->right);
            }
        }
        result=realloc(result,(*returnsize+1)*sizeof(int*));
        *columnsize=realloc(*columnsize,(*returnsize+1)*sizeof(int));
        result[*returnsize]=arr;
        (*columnsize)[*returnsize]=size;
        (*returnsize)++;

    }
    result=reverse1(result,*returnsize);
    reverse2(*columnsize,*returnsize);

    return result;

}

int **reverse1(int **rev,int sizee)
{
int l=0;
int r=sizee-1;
int *temp=NULL;
while(l<r)
{
temp=rev[l];
rev[l++]=rev[r];
rev[r--]=temp;
}
return rev;
}

void reverse2(int *rev,int sizee)
{
int l=0;
int r=sizee-1;
int temp=0;
while(l<r)
{
temp=rev[l];
rev[l++]=rev[r];
rev[r--]=temp;
}

}