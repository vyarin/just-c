#include <stdio.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

double top(void);
void duplicate_top(void);
void swap_top(void);

int main(void)
{
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