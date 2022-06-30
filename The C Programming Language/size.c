#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(void) {
    // Get range of integer
    int max_int = 1;

    for (int i = 0; max_int > 0; i++) {
        max_int *= 2;
    }
    printf("The range of an int is %i to %i, unsigned: 0 to %u\n", max_int, max_int - 1, (unsigned int) (max_int - 1) * 2); // add -1

    // Get range of short
    short max_short = 1;

    for (int i = 0; max_short > 0; i++) {
        max_short *= 2;
    }
    printf("The range of a short int is %hd to %hd, unsigned: 0 to %hu\n", max_short, max_short - 1, (unsigned short) (max_short - 1) * 2); // hd is short format

    long max_long = 1;
    for (int i = 0; max_long > 0; i++) {
        max_long *= 2;
    }
    printf("The range of a long int is %ld to %ld, unsigned: 0 to %lu\n", max_long, max_long - 1, (unsigned long) (max_long - 1) * 2);

    char max_char = 1; // revisit
    for (int i = 0; max_char > 0; i++) {
        max_char *= 2;
        // printf("%hhi\n", max_char - 3);
    }
    printf("The range of a char is %i to %hhi, unsigned: 0 to %hhi\n", max_char, max_char - 1, (unsigned char) (max_char - 1) * 2);
    printf("The range of a char is %i to %hhi, unsigned: 0 to %hhi\n", SCHAR_MIN, SCHAR_MAX, UCHAR_MAX);

    // Get range of float
    printf("The range of a float is %.10e to %.10e\n", -FLT_MAX, FLT_MAX); // prints 10 significant digits and exponent
    printf("The range of a double is %.10e to %.10e\n", -DBL_MAX, DBL_MAX); // dbl_min is the smallest positive normalized number
    printf("The range of a long double is %Le to %Le\n", -LDBL_MAX, LDBL_MAX);
    return 0;

}