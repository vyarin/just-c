#include <stdio.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
    char s[1000];
    int num = 23949;
    itoa(num, s);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;

    // if ((sign = n) < 0)
    // {
    //     n = -n;
    // }
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