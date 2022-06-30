/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x
with the n bits that begin at position p set to the rightmost 
n bits of y, leaving the other bits unchanged.
*/

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    setbits(37036, 7, 9, 16086);
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask = (~((~0) << n)) << (p - 1); // bitmask for n bits starting at p
    y = ((y & ~((~0) << n)) << (p - 1)); // bitmask of rightmost n bits, move bits to position
    return ((x & mask) | y); // return x with rightmost n bits from y moved to position p
}