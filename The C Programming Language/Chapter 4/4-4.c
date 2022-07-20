#include <stdio.h>

#define MAXVAL 100

int sp = 4;
double val[MAXVAL] = {4.0, 6.0, 7.0, 5.0};

double top(void);
void duplicate_top(void);
void swap_top(void);
void clear_stack(void);

int main(void)
{
    swap_top();
    duplicate_top();
    for (int i = 0; i < sp; i++)
    {
        printf("%f\n", val[i]);
    }
    return 0;
}

double top(void)
{
    return val[sp - 1];
}

void duplicate_top(void)
{
    double stack_top = top();
    if (sp < MAXVAL)
    {
        val[sp++] = stack_top;
    }
    else
    {
        printf("error: stack full, can't push %g\n", stack_top);
    }
}

void swap_top(void)
{
    double val1 = val[sp - 2];
    val[sp - 2] = top();
    val[sp - 1] = val1;
}

void clear_stack(void)
{
    sp = 0;
}