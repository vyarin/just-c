#include <stdio.h>

#define SET_ON 0b1111111111111111

int main(void) {
    // AND 
    unsigned short x = 0b1111111111111111;
    x = x & 0177; // 0b0000000011111111, 127
    printf("%i\n", x); // 127

    // OR
    unsigned short y = 0b1010101010101010;
    y = y | SET_ON;
    printf("%i\n", y); // 65535

    // ONES COMPLEMENT -- !
    unsigned short n = 0b1111111111111111;
    n = n & ~0b0000000000111111; // 077

    printf("%i\n", n); // 65535 - 63 = 65472

    return 0;
}