#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *cexpGen();
char *chartoStr(char c);

char c_exp[18] = "1";
char expressions[2] = {'+', '-'};

int main()
{
    cexpGen();
    printf("%s", c_exp);
    return 0;
}

char *cexpGen()
{
    size_t len = strlen(c_exp);
    int now = 1;
    while ((len = strlen(c_exp)) > 0 && c_exp[len - 1] > 10)
    {
        if (c_exp[(strlen(c_exp) - 1)] == '9')
        {
            
        }
        if ((c_exp[strlen(c_exp) - 1]) == '+' || (c_exp[strlen(c_exp) - 1]) == '-')
        {
            c_exp[len++] = ((c_exp[strlen(c_exp) - 2]) + 1);
            c_exp[len] = '\0';
            continue;
        }

        if (now == 1)
        {
            c_exp[len++] = expressions[0];
            c_exp[len] = '\0';
            now++;
            cexpGen();
        }

        if (now == 2)
        {
            c_exp[len++] = expressions[1];
            c_exp[len] = '\0';
            now++;
            cexpGen();
        }

        if (now == 3)
        {
            c_exp[len++] = ((c_exp[strlen(c_exp) - 1]) + 1);
            c_exp[len] = '\0';
            now = 1;
            cexpGen();
        }
    }
}