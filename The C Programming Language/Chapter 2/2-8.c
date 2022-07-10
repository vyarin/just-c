/*
    Write a function rightrot(x,n) that returns the value of the integer x 
    rotated to the right by n bit positions
*/

#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void)
{
    printf("%u\n", rightrot(223, 8));
    printf("%u\n", rightrot(14041, 8));
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    int len = 0;
    unsigned bit = x;

    while ((bit = x >> len) > 0) // Calculate length of word
    {
        len++;
    }
    for (int i = 0; i < n; i++) // Rotate bits to the right
    {
        unsigned last_bit = (x & ~((~0) << 1)) << (len - 1); // Isolate last bit and move to leftmost position
        x = (x >> 1) | last_bit;  // Shift bits to the right and add last bit to the left
    }
    return x;
}