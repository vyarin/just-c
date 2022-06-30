#include <stdio.h>
#include <string.h>

int main(void) {
    for (int i = 0; i < 5; i++) {
        printf("i++\n");
    }

    for (int i = 0; i < 5; ++i) {
        printf("++i\n");
    }

    char Str[1000];
    int i;
 
    printf("Enter the String: ");
    scanf("%s", Str);
 
    // for (i = 0; Str[i] != '\0'; ++i);
    for (i = 0; Str[i] != '\0'; i++);
 
    printf("Length of Str is %d", i);
 
    return 0;
}