/*
    Replace any inputted blanks of a length more than 1 with one space

*/

#include <stdio.h>

int main(void) {
    int c;
    int isSpace = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!isSpace) {
                isSpace = 1;
            }
            else {
                continue;
            }

        }
        else {
            isSpace = 0;
        }
        putchar(c);
    }
    return 0;
}