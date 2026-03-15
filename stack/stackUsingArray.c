#include <stdio.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
        return;
    stack[++top] = value;
}
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        top--;
    }
}

void Top()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top]);
}

void isEmpty()
{
    if (top == -1)
        printf("true\n");
    else
        printf("false\n");
}

void size()
{
    printf("%d\n", top + 1);
}

int main()
{
    int n, value;
    char input[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", input);

        if (strcmp(input, "Push") == 0)
        {
            scanf("%d", &value);
            push(value);
        }
        else if (strcmp(input, "Pop") == 0)
        {
            pop();
        }
        else if (strcmp(input, "Top") == 0)
        {
            Top();
        }
        else if (strcmp(input, "IsEmpty") == 0)
        {
            isEmpty();
        }
        else if (strcmp(input, "Size") == 0)
        {
            size();
        }
    }
}