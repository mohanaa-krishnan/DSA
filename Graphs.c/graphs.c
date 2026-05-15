#include<stdio.h>
#include<stdlib.h>
struct nodeg{
    int vertex;
    struct nodeg *next;
};

struct list{
struct nodeg *head;
struct nodeg *tail;

};



void insertion(int v,struct list **adj);
void adjmatrix(int n,int v);

void dfs(int a,int *visited,struct list **adj);
void bfs(int a,int *visited,struct list **adj);
void display(int n,struct list **adj);

void insertion1(int v,struct list **adj);
void bfs2(int a,struct list **adj);


int main()
{
    int n,v;
    
    scanf("%d %d",&n,&v);
    
    struct list **adj=(struct list**)malloc(sizeof(struct list*)*n);
     int *visited=calloc(n,sizeof(int));
    
    for(int i=1;i<=n;i++)
    {
        adj[i]=(struct list*)malloc(sizeof(struct list));
        adj[i]->head=NULL;
        adj[i]->tail=NULL;
    }
    insertion1(v,adj);
    
   // display(n,adj);
    //for(int i=0;i<n;i++)
    //{
    //dfs(i,visited,adj);
    //}
    
    for(int i=1;i<=n;i++)
    {
        bfs2(i,adj);
        
    }
   // printf("\n");
   // dfs(0,visited,adj);
    
   //adjmatrix(n,v);
   
   return 0;
   
}

void insertion(int v,struct list **adj)
{
    for(int i=0;i<v;i++)
    {
        int p,s;
        scanf("%d %d",&p,&s);
        struct nodeg *newnode=malloc(sizeof(struct nodeg));
        newnode->vertex=s;
        newnode->next=adj[p]->head;
        adj[p]->head=newnode;


    }
}

void dfs(int a,int *visited,struct list **adj)
{
   
    printf("%d ",a);
    visited[a]=1;
    struct nodeg *temp=adj[a]->head;
    while(temp!=NULL)
    {
        if(!visited[temp->vertex])
        {
dfs(temp->vertex,visited,adj);
        }
        temp=temp->next;
    }

}

void bfs(int a,int *visited,struct list **adj)
{
    int Queue[100];
    int front=0;
    int rear=0;
    Queue[rear++]=a;
    visited[a]=1;
    while(front<rear)
    {
        int current=Queue[front++];
        printf("city:%d: ",current);
        struct nodeg *temp=adj[current]->head;
        while(temp!=NULL)
        {
            printf("%d ",temp->vertex);
            if(!visited[temp->vertex])
            {
                //printf("%d ",temp->vertex);
            Queue[rear++]=temp->vertex;
            visited[temp->vertex]=1;
            
        }
    temp=temp->next;
}
        printf("\n");
    }
}

void display(int n,struct list **adj)
{
for (int i=0;i<n;i++)
{
    printf("%d-->",i);
    struct nodeg *temp=adj[i]->head;
    while(temp!=NULL)
    {
        printf("%d-",temp->vertex);
        temp=temp->next;
    }
    printf("\n");
}
}

void adjmatrix(int n,int v)
{
    int adj[n][n];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            adj[i][j]=0;
        }

    }
    int val1,val2;
    for(int i=0;i<v;i++)
    {
        scanf("%d %d",&val1,&val2);
        adj[val1][val2]=1;
        adj[val2][val1]=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}

void insertion1(int v,struct list **adj)
{
    for(int i=0;i<v;i++)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        struct nodeg *newnode=malloc(sizeof(struct nodeg));
        newnode->vertex=q;
        newnode->next=NULL;
        if(adj[p]->head==NULL)
        {
            adj[p]->head=newnode;
            adj[p]->tail=newnode;

        }
        else
        {
            adj[p]->tail->next=newnode;
            adj[p]->tail=newnode;
        }
        struct nodeg *newnode1=malloc(sizeof(struct nodeg));
        newnode1->vertex=p;
        newnode1->next=NULL;
        if(adj[q]->head==NULL)
        {
            adj[q]->head=newnode1;
            adj[q]->tail=newnode1;
        }
        else
        {
            adj[q]->tail->next=newnode1;
            adj[q]->tail=newnode1;
        }
    }
}

void insertion2(int v,struct list **adj)
{
    for(int i=0;i<v;i++)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        struct nodeg *newnode=malloc(sizeof(struct nodeg));
        newnode->vertex=q;
        newnode->next=NULL;
        if(adj[p]->head==NULL)
        {
            adj[p]->head=newnode;
           

        }
        else
        {
            struct nodeg *temp=adj[p]->head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
        struct nodeg *newnode1=malloc(sizeof(struct nodeg));
        newnode1->vertex=p;
        newnode1->next=NULL;
        if(adj[q]->head==NULL)
        {
            adj[q]->head=newnode1;
            
        }
        else
        {
            struct nodeg *temp1=adj[q]->head;
            while(temp1->next!=NULL)
            {
                temp1=temp1->next;
            }
            temp1->next=newnode1;
        }
    }
}

void bfs2(int a,struct list **adj)
{
   
        int current=a;
        printf("city:%d: ",current);
        struct nodeg *temp=adj[current]->head;
        while(temp!=NULL)
        {
            printf("%d ",temp->vertex);
            temp=temp->next;
            
        }
    
        printf("\n");
}
        
    

