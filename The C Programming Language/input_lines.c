#include <stdio.h>
// write a program to print all input lines that are longer than 80 characters
#define MAX_LENGTH 1000
#define MIN_LENGTH 10

int line_length(char line[]);

int main(void) {

    int len;
    char current_line[MAX_LENGTH];
    while ((len = line_length(current_line)) > 0) {
        if (len > MIN_LENGTH) {

            printf("%s\n", current_line);
        }
    }
    printf("%s\n", current_line);
    return 0;
}

int line_length(char line[]) {
    int c, len;

    for (len = 0; len < MAX_LENGTH - 1 && (c = getchar()) != EOF && c != '\n'; ++len) {
        line[len] = c;
    }
    if (c == '\n') {
        line[len] = c;
        ++len;
    }
    line[len] = '\0';
    return len;
}