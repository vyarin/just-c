#include <stdio.h>
// write a program to print all input lines that are longer than 80 characters
#define MAX_LENGTH 1000

int line_length(char line[]);

int main(void) {

    int len;
    char current_line[MAX_LENGTH];
    while ((len = line_length(current_line)) >= 0) {
        if (current_line[0] == '\0') {
            continue;
        }
        printf("%s\n", current_line);
    }
    return 0;
}

int line_length(char line[]) {
    int c, i;
    int prev_character;
    int end_of_string = 0;

    for (i = 0; i < MAX_LENGTH - 1 && (c = getchar()) != EOF; ++i) {
        if ((c == '\t' || c == ' ' || c == '\n') && (prev_character != '\t' && prev_character != ' ')) {
            end_of_string = i;
        }
        if (c == '\n') {
            break;
        }
        line[i] = c;
        prev_character = c;
    }
    line[end_of_string] = '\0';
    if (c == EOF) {
        return -1;
    }
    return i;
}