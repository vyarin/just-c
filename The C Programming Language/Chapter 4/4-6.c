#include <stdio.h>
#include <math.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <string.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define FUNCTION 'F' /* signal that a function was found */
#define VARIABLE 'V' /* signal that a variable was found */
#define BUFFSIZE 100
#define MAXVAL 100

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void alpha_op(char s[]);
double var_lookup(double v);

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case FUNCTION:
            alpha_op(s);
            break;
        case '^':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numberic operand */
int getop(char s[])
{
    int i = 0;
    int c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-' && !isalpha(c))
    {
        return c; /* not a number */
    }
    if (isalpha(c))
    {
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        ungetch(c);
        return FUNCTION;
    }
    if (c == '-') // negative number
    {
        if (!isdigit(c = getch()))
        {
            ungetch(c);
            return '-';
        }
        s[++i] = c;
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

char buf[BUFFSIZE]; /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

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

void alpha_op(char s[])
{
    if (!strcmp(s, "exp"))
    {
        push(exp(pop()));
    }
    else if (!strcmp(s, "sin"))
    {
        push(sin(pop()));
    }
    else if (!strcmp(s, "cos"))
    {
        push(cos(pop()));
    }
    else if (!strcmp(s, "tan"))
    {
        push(tan(pop()));
    }
    else
    {
        printf("error: unknown command %s\n", s);
    }
}

double vars[26];

double var_lookup(double v)
{
    return vars[toupper(v) - 'A'];
}