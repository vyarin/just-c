#include <stdio.h>
// write a program to print all input lines that are longer than 80 characters
#define MAX_LENGTH 1000
#define MIN_LENGTH 10

int get_line(char line[]);
void reverse_line(char line[], int length);

int main(void) {

    int len;
    char current_line[MAX_LENGTH];
    while ((len = get_line(current_line)) > 0) {
        reverse_line(current_line, len);
        printf("%s\n", current_line);
    }
    printf("%s\n", current_line);
    return 0;
}

// Copy inputted line and return length
int get_line(char line[]) {
    int c, i;

    for (i = 0; i < MAX_LENGTH - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    // if (c == '\n') {
    //     line[i] = c;
    //     ++i;
    // }
    line[i] = '\0';

    return i;
}

// Reverse char array
void reverse_line(char line[], int length) {
    // get length of array by dividing size of array by size od data type (reminder)
    
    length = length - 1;
    for (int i = length; i > length / 2; i--) {
        int temp = line[i];
        line[i] = line[(length) - i];
        line[(length) - i] = temp;
    }
    

}