#include <stdio.h>

#define MAX_LINE 1000

char *escape(char s[], char t[]);
int get_line(char s[], int limit);

int main(void)
{
    char line[MAX_LINE];
    char new_line[MAX_LINE];
    while (get_line(line, MAX_LINE))
    {
        printf("%s\n", escape(new_line, line));
    }
    return 0;
}

int get_line(char s[], int limit)
{
    int c;
    int i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF; i++)
    {
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}

char *escape(char s[], char t[])
{
    int j = 0;
    for (int i = 0; t[i] != '\0'; i++)
    {
        switch (t[i])
        {
        case '\n':
            s[j] = '\\';
            s[j + 1] = 'n';
            j += 2;
            break;
        case '\t':
            s[j] = '\\';
            s[j+1] = 't';
            j += 2;
            break;
        default:
            s[j] = t[i];
            j++;
            break;
        }
    }
    s[j] = '\0';
    return s;
}