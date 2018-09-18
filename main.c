#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *cexpGen();
void append(char *s, char c);

char c_exp[] = "1";
char expressions[2] = {'+', '-'};

int main()
{
    cexpGen();
    printf("%s", c_exp);
    return 0;
}

char *cexpGen()
{
    int now = 1;
    while ((c_exp[strlen(c_exp) - 1]) > 10)
    {
        if ((c_exp[strlen(c_exp) - 1]) == '+' || (c_exp[strlen(c_exp) - 1]) == '-')
        {
            append(c_exp, ((c_exp[strlen(c_exp) - 2]) + 1));
            continue;
        }

        if (now = 1)
        {
            append(c_exp, expressions[1]);
            now++;
            cexpGen();
        }

        if (now = 2)
        {
            append(c_exp, expressions[2]);
            now++;
            cexpGen();
        }

        if (now = 3)
        {
            append(c_exp, ((c_exp[strlen(c_exp) - 1]) + 1));
        }
    }
}

void append(char *s, char c)
{
    s[strlen(s)] = c;
    s[strlen(s) + 1] = '\0';
}