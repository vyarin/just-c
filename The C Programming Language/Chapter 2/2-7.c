/*
    Write a function invert(x,p,n) that returns x with the n bits 
    that begin at position p inverted (i.e. 1 changed to 0), 
    leaving others unchanged
*/

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void) 
{
    printf("%u\n", invert(5578, 5, 7));
    printf("%u\n", invert(26366, 2, 11));
    printf("%u\n", invert(27583, 1, 14));
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{   
    unsigned mask = (~((~0) << n) << (p - 1));
    return ((x & (~mask)) | (~x & mask));
}