#include <stdio.h>

int main() {
    double nc;
    
    for (nc = 0; getchar() != EOF; ++nc)
        ; // For statements must have a body according to c. A null statement, a semicolon is used instead
    printf("%.0f, nc");

    return 0;
}