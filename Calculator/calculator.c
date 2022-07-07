#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char value;
    struct node *next;
}
node;

void push(node **stack, char value);

int pop(node **stack);

int is_empty(node *stack);

int main(void)
{
    return 0;
}