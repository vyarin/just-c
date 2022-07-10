#include <stdio.h>
#include <ctype.h>

int htoi(char string[]);

int main(void)
{
    int decimal_form = htoi("0XA83efcd");
    
    if (decimal_form < 0)
    {
        printf("Invalid hex string");
    }
    else
    {
        printf("%i", decimal_form);
    }
    return 0;
}

int htoi(char *string)
{
    // Find length of string without "0x" or "0X"
    int prefixed_string = 0;

    // Ignore "0x" or "0X"
    if (((string[0] == '0')) && ((string[1] == 'x') || (string[1] == 'X')))
    {
        prefixed_string = 2;
    }

    // Determine starting place value of hex string depending on length
    int place_value = 1;

    // Initialize i as default 1 to correctly calculate place value starting
    // from 16^0 
    for (int i = 1 + prefixed_string; string[i] != '\0'; i++)
    {
        place_value *= 16;
    }

    // Determine decimal value of hex string
    int int_value = 0;

    for (int c = 0 + prefixed_string; string[c] != '\0'; c++) {
        // Validate hexadecimal digit (0-9, a-f, A-F)
        if (isdigit(string[c])) {
            int_value += (string[c] - '0') * place_value;
        }
        else if (string[c] >= 'A' && string[c] <= 'F')
        {
            int_value += (string[c] - 'A' + 10) * place_value;
        }
        else if (string[c] >= 'a' && string[c] <= 'f')
        {
            int_value += (string[c] - 'a' + 10) * place_value;
        }
        else
        {
            return -1; // Invalid hexadecimal string
        }
        place_value /= 16;
    }
    return int_value;
}