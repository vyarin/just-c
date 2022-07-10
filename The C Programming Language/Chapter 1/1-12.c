#include <stdio.h>

int main(void) {
    int c;

    int inWord = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {

            // Ignore all inputted whitespace except the first to
            // prevent extra new lines
            if (inWord) {
                
                // Add a new line to print one word on every line
                putchar('\n');

                // The first inputted whitespace after a different
                // character indicates a new word has been inputted
                inWord = 0;
            }            
        }
        else {
            putchar(c);

            // Characters other than whitespace are inputted, therefore
            // the input is currently in a word
            inWord = 1;
        }
    }
    return 0;
}