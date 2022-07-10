#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
    printf("%u\n", bitcount(13942)); // 9 bits
    printf("%u\n", bitcount(14327)); // 12 bits
    printf("%u\n", bitcount(13)); // 3 bits
    printf("%u\n", bitcount(0)); // 0 bits
    printf("%u\n", bitcount(349043)); // 11 bits
    printf("%u\n", bitcount(0xFFFFFFFF)); // 32 bits
    return 0;
}

int bitcount(unsigned x)
{
    int b = 0; // bit counter

    while (x)
    {
        x &= (x-1); // clear rightmost bit
        b++; // increment bit count
    }
    return b;
}