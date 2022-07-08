#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int value;
    struct node *next;
}
node;

node *operators = NULL;

void push(node **stack, int value);

char pop(node **stack);

int is_empty(node *stack);

int precedence(char operator);

int eval(char *expression);

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

int precedence(char operator)
{
    int op_precedence = 0;
    switch (operator)
    {
    case '^':
        op_precedence = 4;
        break;
    
    case '/':
        op_precedence = 3;
        break;
    
    case '*':
        op_precedence = 3;
        break;
    
    case '+':
        op_precedence = 2;
        break;
    
    case '-':
        op_precedence = 2;
        break;
    
    default:
        break;
    }
    return op_precedence;
}

int eval(char *expression)
{
    int in_num = 0;
    int current_num = 0;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            if (!in_num)
            {
                in_num = 1;
            }
            current_num *= 10;
            current_num += i;
        }
        else
        {
            if (in_num)
            {
                // Push to output queue
            }
        }
    }
    return 0;
}