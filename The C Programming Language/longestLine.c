#include <stdio.h>
#define MAXLINE 20 /* maximum input line length */
int getline(char line[], int maxline);
void copy(char to[], char from[]);
/* print the longest input line */
int main()
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) /* there was a line */
    {
        printf("%s\n", longest);
        printf("%i\n", max);
    }
    return 0;
}
/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, len;
    int i = 0;
    for (len = 0; (c = getchar()) != EOF && c != '\n'; ++len)
    {
        if (i < lim - 1)
        {
            s[i] = c;
            ++i;
        }
    }
    if (c == '\n')
    {
        if (len < lim)
        {
            s[i] = c;
            ++i;
        }
        ++len;
    }
    s[i] = '\0';
    return len;

}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}
