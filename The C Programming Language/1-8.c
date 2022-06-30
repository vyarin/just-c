#include <stdio.h>

int main() {
    int c;
    int sequences = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            ++sequences;
        }
    }
    printf("There are %i spaces, tabs and lines\n", sequences);
    return 0;
}