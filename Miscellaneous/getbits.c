#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main(void) 
{
    printf("%i", getbits(0b1110101101010010, 4, 2));
    return 0;
}

/* get n bits (to the right) from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n) & ~(~0 << n));
}