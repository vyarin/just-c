/* Replace tabs in input with blanks to space to the next tab stop */

#include <stdio.h>

#define MAX_LINE 1000
#define TAB_STOP 8

int get_line(char line[]);

int main(void) {

    // Current inputted line
    char current_line[MAX_LINE];

    // Print lines until end of file
    while (get_line(current_line) > 0) {
        printf("%s", current_line);
    }
    return 0;
}

int get_line(char line[]) {
    int c;
    int len = 0;

    while (len < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n') {
        if (c == '\t') {
            // Replace tabs with spaces to the next tab stop
            int tab_spaces = TAB_STOP - len % TAB_STOP;
            for (int j = 0; j < tab_spaces && len < MAX_LINE - 1; j++) {
                line[len] = '.';
                ++len;
            }
        }
        else {
            // Print character
            line[len] = c;
            ++len;
        }
    }
    if (c == '\n') {
        line[len] = c;
        ++len;
    }
    line[len] = '\0';

    return len;
}