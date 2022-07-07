#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char value;
    struct node *next;
}
node;

void push(node **stack, char value);

char pop(node **stack);

int is_empty(node *stack);

int main(void)
{
    return 0;
}

void push(node **stack, char value)
{
    node *new = malloc(sizeof(node));
    new->value = value;
    new->next = *stack;
    *stack = new;
}