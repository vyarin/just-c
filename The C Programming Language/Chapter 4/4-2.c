/*
   Extend atof to handle scientific notation of the form
        123.45e-6
   where a floating-point number may be followed by e or E 
   and an optionally signed exponent
*/

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(void)
{
    printf("%lf\n", atof("1.1e4"));
    printf("%lf\n", atof("3.141592"));
    printf("%lf\n", atof("5.2E-1"));
    return 0;
}

double atof(char s[])
{
    double val, power, exponent;
    int i, sign, exp_sign;
    double base = 1.0;

    for (i = 0; isspace(s[i]); i++);

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }


    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
        {
            i++;
        }
        for (exponent = 0.0; isdigit(s[i]); i++)
        {
            exponent = 10.0 * exponent + (s[i] - '0');
        }
        for (int i = 0; i < exponent; i++)
        {
            base *= 10.0;
        }
        if (exp_sign == -1)
        {
            base = 1 / base;
        }
    }
    

    return (sign * val / power) * base;
}