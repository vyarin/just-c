/* Write an alternate version of squeeze(s1,s2) that deletes each character
   in the string s1 that matches any character in the string s2. */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[] = "eovdedn";
    char s2[] = "even";
    squeeze(s1, s2);
    printf("%s", s1);
}

void squeeze(char s1[], char s2[])
{
    int position = 0;
    for (int i = 0; s2[i] != '\0'; i++)
    {
        for (int j = 0; s1[j] != '\0'; j++)
        {
            if (s2[i] != s1[j])
            {
                s1[position++] = s1[j];
            }
        }
        s1[position] = '\0';
        position = 0;
    }
}