/* 
   Write a version of itoa that accepts three arguments instead of
   two. The third argument is a minimum field width; the converted number must
   be padded with blanks on the left if necessary to make it wide enough.
*/

#include <stdio.h>

void itoa(int n, char s[], int width);
void reverse(char s[]);

int main(void)
{
    char s[1000];
    int num = 23949;
    itoa(num, s, 8);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[], int width)
{
    int ncpy = n;
    int digits = 0;
    do
    {
        digits++;
    } while ((ncpy /= 10) != 0);
    
    int i, sign;

    sign = n;
    i = 0;
    if (sign >= 0)
    {
        do
        {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0);
    }
    else
    {
        do
        {
            s[i++] = -(n % -10) + '0';
        } while (-(n /= 10) > 0);
    }
    if (sign < 0)
    {
        s[i++] = '-';
    }

    if (digits < width)
    {
        for (int j = 0; j < width - digits; j++)
        {
            s[i++] = ' ';
        }
    }

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        len++;
    }

    for (int i = 0; i < (len/2); i++)
    {
        int tmp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = tmp;
    }
}