/* 
    Write a function expand(s1, s2) that expands shorthand notations 
    like a-z in the string s1 into the equivalent complete list abc...xyz
    in s2. Allow for letters of either case and digits, and be prepared 
    to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a 
    leading or trailing - is taken literally.
*/

#include <stdio.h>

void expand(char *s1, char s2[]);

int main(void)
{
    char* string1 = "a-z1-9hhf--";
    char string2[1000];
    expand(string1, string2);
    printf("%s\n", string2);

    return 0;
}

void expand(char* s1, char s2[])
{
    int start = 0;
    int end = 0;
    int in_range = 0;
    int h = 0; // s2 index

    for (int i = 0; s1[i] != '\0'; i++) // bug - loop terminates on last range
    {
        if (!in_range) // if no range exists
        {
            if (start && s1[i] == '-') // check for hyphen between a range
            {
                in_range = 1;
            }
            else
            {
                start = s1[i]; // define start character
                s2[h] = start; // print start characters
                h++;
            }
        }
        else // if a range exists with no end
        {
            end = s1[i];
        }

        if (start && end) // if a range is defined, expand
        {
            if (start < end)
            {
                for (int j = start + 1; j <= end; j++) // +1 skips start as start is already printed
                {
                    s2[h] = j;
                    h++;
                }
            }
            start = 0;
            end = 0;
            in_range = 0;
        }
    }
    s2[h] = '\0';
}