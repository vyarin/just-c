/* 
   Write the function strrindex (s, t), which returns the position
   of the rightmost occurrence of t in s, or -1 if there is none
*/

#include <stdio.h>
#include <string.h>

int strrindex(char string[], char pattern[]);

int main(void)
{
    return 0;
}

int strrindex(char string[], char pattern[])
{
    int i;

    int string_length = strlen(string);
    int pattern_length = strlen(pattern);

    for (int i = string_length - 1; i >= 0; i--)
    {
        for (int j = i, k = pattern_length - 1; string[j] == pattern[k] && k >= 0; j--, k--)
        {
            if (k == 0)
            {
                return i - pattern_length + 1;
            }
        }
    }
    return -1;
}