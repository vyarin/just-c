#include <stdio.h>

void lower(char string[]);

int main(void)
{
    char string[] = "The Quick brown FOX jumps OveR the Lazy DOG";
    lower(string);

    printf("%s", string);
    return 0;
}

void lower(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        string[i] = (string[i] >= 'A' && string[i] <= 'Z') ? string[i] + 32 : string[i];
    }
}