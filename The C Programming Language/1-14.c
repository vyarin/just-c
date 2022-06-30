#include <stdio.h>

int main() {
    int c;

    // Array storing count of all 26 characters
    int chars[26];
    for (int i = 0; i < 26; i++) {
        chars[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        // Check if letter is alpha (can be done with isalpha())
        if ((c > 64 && c < 91) || (c > 96 || c < 123)) {
            if (c > 96) {
                ++chars[c - 97];
            }
            else {
                ++chars[c - 65];
            }
        }
    }

    // Print histogram
    printf("LETTER FREQUENCIES\n\n");
    for (int i = 0; i < 26; i++) {
        printf("%c ", i + 65);
        for (int j = 0; j < chars[i]; j++) {
            printf("=");
        }
        printf("\n");
    }
}