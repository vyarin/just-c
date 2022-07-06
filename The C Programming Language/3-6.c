/* 
   Write a version of itoa that accepts three arguments instead of
   two. The third argument is a minimum field width; the converted number must
   be padded with blanks on the left if necessary to make it wide enough.
*/

#include <stdio.h>

void itoa(int n, char s[]);

int main(void)
{
    return 0;
}

void itoa(int n, char s[])
{
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
    s[i] = '\0';
    reverse(s);
}