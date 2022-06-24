#include <stdio.h>

int main() {
    printf("%i", EOF);
    char string[10];
    int position = 0;
    int character;

    while (position != 10) {
        character = getchar();
        string[position] = character;
        position++;
    }
    // Everything is stored internally as a bit pattern, therefore int and char can be used
    // to display characters. 65 is A.
    putchar(0b1000001);
    // int c = getchar() != EOF;
    // printf("%i", c);
    
    return 0;
}