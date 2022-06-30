/*
 * Write a program to check a C Program for rudimentary syntax errors 
 * like unbalanced parentheses, brackets and braces. Don't forget about 
 * quotes, both single and double, escape sequences, and comments.
 * 
 */

// program does not detect unbalanced parentheses, this can be solved with
// a stack data structure

#include <stdio.h>

#define PROGRAM 0 // Other characters in the program
#define GROUPING 1 // Parentheses, brackets and braces
#define STRING_LIT 2 // String literal
#define CONSTANT 3 // Character constant
#define INL_COMMENT 4 // Inline comment
#define MUL_COMMENT 5 // Multiline comment
#define ESCAPE 6 // Escape characters

int parentheses = 0;
int brackets = 0;
int braces = 0;

int strings = 0;
int constants = 0;
int multiline_comments = 0;


void check_errors();
void count_groupings(int character);

int main(void) {
    // Check program for syntax errors
    check_errors();

    // Display any errors to user
    if (parentheses) {
        printf("Mismatched parentheses\n");
    }
    if (brackets) {
        printf("Mismatched brackets\n");
    }
    if (braces) {
        printf("Mismatched braces\n");
    }
    if (strings) {
        printf("Mismatched string\n");
    }
    if (constants) {
        printf("Mismatched constant\n");
    }
    if (multiline_comments) {
        printf("Mismatched comment\n");
    }
    
    return 0;
}

void check_errors() {
    // State machine
    int c;
    int previous_character;
    int state = 0;

    // Track previous state when in a character constant
    int prev_escape_state = 0;

    while ((c = getchar()) != EOF) {
        switch (state) {
        case PROGRAM:
            // Check is a string begins
            if (c == '"') {
                strings++;
                state = STRING_LIT;
            }
            // Check if a constant begins
            else if (c == '\'') {
                constants++;
                state = CONSTANT;
            }
            // Check if a comment begins
            else if (previous_character == '/') {
                if (c == '/') {
                    state = INL_COMMENT;
                }
                else if (c == '*') {
                    multiline_comments++;
                    state = MUL_COMMENT;
                }
            }
            else {
                // Check if character is a parenthesis, bracket or brace
                count_groupings(c);
            }
            break;

        case STRING_LIT:
            // Skip character constants
            if (c == '\\') {
                prev_escape_state = STRING_LIT;
                state = ESCAPE;
                break;
            }
            // Exit state when string literal ends
            if (c == '"') {
                strings--;
                state = PROGRAM;
            }
            break;

        case CONSTANT:
            // Skip character constants
            if (c == '\\') {
                prev_escape_state = CONSTANT;
                state = ESCAPE;
                break;
            }
            // Exit state when constant ends
            if (c == '\'') {
                constants--;
                state = PROGRAM;
            }
            break;

        case INL_COMMENT:
            // Exit state when inline comment ends
            if (c == '\n') {
                state = PROGRAM;
            }
            break;

        case MUL_COMMENT:
            // Exit state when multiline comment ends
            if (c == '/' && previous_character == '*') {
                multiline_comments--;
                state = PROGRAM;
            }
            break;
        
        case ESCAPE:
            // Skip current character and revert to previous state
            state = prev_escape_state;
            break;

        default:
            // Reset state to PROGRAM
            state = PROGRAM;
        } 

        previous_character = c;
    }
}

void count_groupings(int character) {
    // Identify type of grouping, if applicable
    switch (character) {
    case '(':
        parentheses++;
        break;

    case '[':
        brackets++;
        break;

    case '{':
        braces++;
        break;

    case ')':
        parentheses--;
        break;
    
    case ']':
        brackets--;
        break;

    case '}':
        braces--;
        break;
    
    default:
        break;
    }
}