#include <stdio.h>

#define BUFFSIZE 100

int getch(void);
void ungetch(int);
void ungets(char s[]);

int pushback = 0;

int main(void)
{
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