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