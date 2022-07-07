/*
  Write the function any (s 1, s2 ), which returns the first location
  in the string s 1 where any character from the string s2 occurs, or -1 if s 1
  contains no characters from s2.
*/

#include <stdio.h>

int any(char s1[], char s2[]);

int main(void)
{
    return 0;
}

int any(char s1[], char s2[])
{
    int position = 0;
    for (int i = 0; s2[i] != '\0'; i++)
    {
        for (int j = 0; s1[j] != '\0'; j++)
        {
            if (s2[i] == s1[j])
            {
                return j;
            }
        }
    }
    return -1;
}