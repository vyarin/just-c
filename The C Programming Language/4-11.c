#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100 
#define NUMBER '0'
#define BUFFSIZE 100
#define MAXVAL 100

int getop(char[]);
void push(double);
double pop(void);

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

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    static int buffer = 0;
    static char bufval;
    int i, c;
    if (buffer && (bufval != ' ' && bufval != '\t'))
    {
        buffer = 0;
        s[0] = c = bufval;
    }
    else
    {
        while ((s[0] = c = getchar()) == ' ' || c == '\t')
            ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if (c != EOF)
        if (buffer)
            printf("too many characters in buffer\n");
        else
            bufval = c;
    return NUMBER;
}