#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}
node;

void push(node **stack, int value);

char pop(node **stack);

int is_empty(node *stack);

int main(void)
{
    return 0;
}

void push(node **stack, int value)
{
    node *new = malloc(sizeof(node));
    new->value = value;
    new->next = *stack;
    *stack = new;
}

char pop(node **stack)
{
    node *tmp = *stack;
    if (tmp) // Only pop if list is not empty
    {
        *stack = tmp->next;
        return tmp->value;
    }
    return -1;
}

int is_empty(node *stack)
{
    return !stack;
}