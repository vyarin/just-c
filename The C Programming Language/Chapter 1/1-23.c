/* Remove all comments from a C program */

#include <stdio.h>

#define MAX_LINE 3000



int get_line(char line[]);
void remove_comments(char line[], char new_line[], int line_length);

int main(void) {
    int length = 0;
    char current_line[MAX_LINE];
    char new_line[MAX_LINE];

    while ((length = get_line(current_line)) != 0) {
        remove_comments(current_line, new_line, length);
        printf("%s", new_line);
    }
    return 0;
}

// Get current inputted line
int get_line(char line[]) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && i != MAX_LINE - 1; i++) {
        line[i] = c;
    }
    line[i] = '\0';
    return i;

}

// Remove all comments from line
void remove_comments(char line[], char new_line[], int line_length) {
    int new_line_position = 0;

    int in_inline_comment = 0;
    int in_multiline_comment = 0;

    int in_string = 0;
    int in_constant = 0;
    int in_backslash = 0;

    for (int i = 0; i < line_length - 1; i++) {
        if (!in_inline_comment && !in_multiline_comment) {
            if (in_backslash) {
                in_backslash = 0;
            }
            else if (line[i] == '\\') {
                in_backslash = 1;
            }
            else if (!in_constant && line[i] == '"') {
                in_string = !in_string;
            }
            else if (!in_string && line[i] == '\'') {
                in_constant = !in_constant;
            }
        }


        if (!in_string && !in_constant) {
            if (!in_multiline_comment) {
                if (line[i] == '/' && line[i + 1] == '/') {
                    in_inline_comment = 1;
                }
                if (line[i] == '\n' && in_inline_comment) {
                    in_inline_comment = 0;
                }
            }
            if (!in_inline_comment) {
                if (line[i] == '/' && line[i + 1] == '*') {
                    in_multiline_comment = 1;
                }
                if (line[i] == '*' && line[i + 1] == '/') {
                    in_multiline_comment = 0;
                }
            }
        }


        if (!in_multiline_comment && !in_inline_comment) {
            new_line[new_line_position] = line[i];
            new_line_position++;
        }

    }
    new_line[new_line_position] = '\0';
}