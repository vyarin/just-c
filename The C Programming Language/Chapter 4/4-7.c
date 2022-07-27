#include <stdio.h>

#define BUFFSIZE 100

int getch(void);
void ungetch(int);
void ungets(char s[]);

char buf[BUFFSIZE]; /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int main(void)
{
    ungets("hello");
    for (int i = 0; i < BUFFSIZE; i++)
    {
        printf("%c", buf[i]);
    }
    return 0;
}



int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push back on input */
{
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (bufp >= BUFFSIZE)
            printf("ungetch: too many characters\n");
        else
            buf[bufp++] = s[i];
    }
}