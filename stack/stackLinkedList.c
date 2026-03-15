#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 101

struct node
{
    char data[MAX];
    struct node *next;
};

struct node *top = NULL;
int count = 0;

void push(char x[])
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->data, x);
    temp->next = top;
    top = temp;
    count++;
}

void Pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    struct node *temp = top;
    top = top->next;
    free(temp);
    count--;
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("%s\n", top->data);
}

void size()
{
    printf("%d\n", count);
}

void IsEmpty()
{
    if (top == NULL)
        printf("true\n");
    else
        printf("false\n");
}

int main()
{
    int n;
    char input[150];

    scanf("%d", &n);
    getchar();

    if (n == 0)
        return 0;

    for (int i = 0; i < n; i++)
    {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strncmp(input, "Push ", 5) == 0)
        {
            push(input + 5);
        }
        else if (strcmp(input, "Pop") == 0)
        {
            Pop();
        }
        else if (strcmp(input, "Top") == 0)
        {
            peek();
        }
        else if (strcmp(input, "IsEmpty") == 0)
        {
            IsEmpty();
        }
        else if (strcmp(input, "Size") == 0)
        {
            size();
        }
    }

    return 0;
}