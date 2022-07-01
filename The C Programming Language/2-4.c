/* Write an alternate version of squeeze(s1,s2) that deletes each character
   in the string s1 that matches any character in the string s2. */

#include <stdio.h>

void squeeze(char s1[], char s2[])
{
    int position = 0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] != s2[j])
            {
                s2[position++] = s2[j];
            }
        }
        s2[position] = '\0';
        position = 0;
    }
}