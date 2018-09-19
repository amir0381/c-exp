#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *cexpGen();
char *chartoStr(char c);

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
            strcat(c_exp[strlen(c_exp)], chartoStr(((c_exp[strlen(c_exp) - 2]) + 1)));
            continue;
        }

        if (now = 1)
        {
            strcat(c_exp[strlen(c_exp)], chartoStr(expressions[0]));
            now++;
            cexpGen();
        }

        if (now = 2)
        {
            strcat(c_exp[strlen(c_exp)], chartoStr(expressions[1]));
            now++;
            cexpGen();
        }

        if (now = 3)
        {
            strcat(c_exp[strlen(c_exp)], chartoStr(((c_exp[strlen(c_exp) - 1]) + 1)));
        }
    }
}

char *chartoStr(char c)
{
    char s[2] = {c, '\0'};
    return s;
}