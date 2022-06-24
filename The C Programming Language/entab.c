/* Replace string of blanks by the minimum numbers of tabs and 
blanks to achieve the same spacing */

#include <stdio.h>

#define MAX_LINE 1000
#define TAB_STOP 8

int get_line(char line[]);

int main(void) {
    int c;
    int position = 0;
    int spaces = 0;

    while ((c = getchar()) != EOF) {
        // Count spaces
        if (c == ' ') {
            ++spaces;
        }
        else {
            if (spaces) {
                int first_tab = TAB_STOP - position % TAB_STOP;
                position += spaces;
                // Fill spaces to the next tab stop if possible
                if (first_tab <= spaces) {
                    printf("\t");
                    spaces -= first_tab;
                }
                // Fill spaces with tabs or spaces depending on amount of spaces
                while (spaces > 0) {
                    if (TAB_STOP <= spaces) {
                        printf("\t");
                        spaces -= TAB_STOP;
                    }
                    else {
                        printf(".");
                        --spaces;
                    }
                }
            }
            printf("%c", c);
            // Reset current position every new line
            if (c == '\n') {
                position = 0;
            }
            else {
                ++position;
            }
        }
    }
    return 0;
}