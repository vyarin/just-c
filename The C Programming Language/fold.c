/* Fold long input lines into two or more shorter lines 
after the last non-blank character */

#include <stdio.h>

#define MAX_LINE 1000
#define MAX_COLUMN 50
#define TAB_STOP 8

int main(void) {
    int c;
    int position = 0;
    int line_length = 0;

    char word[MAX_LINE];

    while ((c = getchar()) != EOF) {
        word[position] = c;
        line_length++;
        position++;

        // Check when a new word has been entered
        if (c == '\t' || c == ' ' || c == '\n') {
            // End string
            word[position] = '\0';

            // Keep track of tab lengths
            int current_tab_length = 0;
            int new_line_tab_lenth = 0;

            if (c == '\t') {
                // Add length of tab onto the current length
                current_tab_length = TAB_STOP - line_length % TAB_STOP;
                line_length += current_tab_length;

                // Calculate length of tab on a new line
                new_line_tab_lenth = TAB_STOP - position % TAB_STOP;
            } 

            // Move to a new line when the line length exceeds the maximum value
            if (line_length > MAX_COLUMN) {
                printf("\n");
                line_length = position - current_tab_length + new_line_tab_lenth;
            }

            // Print word
            printf("%s", word);
            position = 0;
        }
        
    }
    return 0;

}