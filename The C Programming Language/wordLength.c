#include <stdio.h>

int main() {
    int c;

    int wordLengths[4] = {0, 0, 0, 0};

    int wordLength = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (wordLength) {
                if (wordLength <= 2) {
                    ++wordLengths[0];
                }
                else if (wordLength <= 4) {
                    ++wordLengths[1];
                }
                else if (wordLength <= 6) {
                    ++wordLengths[2];
                }
                else if (wordLength <= 8) {
                    ++wordLengths[3];
                }

                wordLength = 0;
            }
        }
        else {
            ++wordLength;
        }
    }
    printf("WORD LENGTH FREQUENCIES\n\n");
    for (int i = 0; i < 4; i++) {
        printf("%i to %i ", i * 2, i * 2 + 2);
        for (int j = 0; j < wordLengths[i]; j++) {
            printf("=");
        }
        printf("\n");
    }
    return 0;
}