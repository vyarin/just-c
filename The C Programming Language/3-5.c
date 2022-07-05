/*
  Write the function itob(n,s,b) that converts the integer n into a
  base b character representation in the string s.
*/

#include <stdio.h>

int main(void)
{
    char strin[1000];
    itob(240, strin, 16);
    printf("%s", strin);
    return 0;
}