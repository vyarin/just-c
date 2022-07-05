/*
  Write the function itob(n,s,b) that converts the integer n into a
  base b character representation in the string s.
*/

#include <stdio.h>

int itob(int num, char str[], int base);

void reverse(char str[]);

int main(void)
{
    char strin[1000];
    itob(240, strin, 16);
    printf("%s", strin);
    return 0;
}

int itob(int num, char str[], int base)
{
    if (base > 36) // Cut off maximum unique digits at 36 (0-9, A-Z)
    {
        return -1;
    }
    int position = 0;
    do
    {
        int digit = num % base;
        if (digit > 9)
        {
            str[position++] = digit + 55;
        }
        else 
        {
            str[position++] = digit + '0';
        }
        num /= base;
    } while (num != 0);

    str[position] = '\0';

    return 1;
}

void reverse(char str[])
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        len++;
    }

    for (int i = 0; i < (len/2); i++)
    {
        int tmp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = tmp;
    }
}