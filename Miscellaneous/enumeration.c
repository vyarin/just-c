#include <stdio.h>

enum boolean {FALSE, TRUE}; // false is assigned a value of 0, true, 1

int main(void) {

    if (TRUE) {
        printf("okay\n");
    }

    int x = 0b010 ^ 0b111; // XOR, 101 (5)
    int y = 0b010 & 0b111; // AND, 010 (2)

    printf("%i\n", (x << 6) >> 3);
    return 0;
}