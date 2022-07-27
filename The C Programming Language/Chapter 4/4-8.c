#include <stdio.h>

#define BUFFSIZE 100

int getch(void);
void ungetch(int);
void ungets(char s[]);

int pushback = 0;
char pchar;

int main(void)
{
    return 0;
}

int getch(void) /* get a (possibly pushed back) character */
{
    if (pushback)
    {
        pushback = 0;
        return pchar;
    }
    else
    {
        return getchar();
    }
}

void ungetch(int c) /* push back on input */
{
    if (pushback)
        printf("ungetch: too many characters\n");
    else
    {
        pushback = 1;
        pchar = c;
    }
}