#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/tinyexpr.h"

void cexpGen();

char c_exp[18] = "1";
char expressions[2] = {'+', '-'};
int now = 1;

int main()
{
    cexpGen();
    printf("%s", c_exp);
    return 0;
}

void cexpGen()
{
    size_t len = strlen(c_exp);
    while ((len = strlen(c_exp)) > 0 && c_exp[len - 1] > 10)
    {
        if (now == 1)
        {
            c_exp[len++] = expressions[0];
            c_exp[len] = '\0';

            c_exp[len++] = ((c_exp[strlen(c_exp) - 2]) + 1);
            c_exp[len] = '\0';

            now++;

            if (c_exp[(strlen(c_exp) - 1)] == '9')
            {
                if (te_interp(c_exp, 0) == 100)
                {
                    int i = 1;
                    printf("%c   %s", i, c_exp);
                    i++;
                }
            }

            cexpGen();
        }

        if (now == 2)
        {
            c_exp[len++] = expressions[1];
            c_exp[len] = '\0';

            c_exp[len++] = ((c_exp[strlen(c_exp) - 2]) + 1);
            c_exp[len] = '\0';

            now++;

            if (c_exp[(strlen(c_exp) - 1)] == '9')
            {
                if (te_interp(c_exp, 0) == 100)
                {
                    int i = 1;
                    printf("%c   %s", i, c_exp);
                    i++;
                }
            }

            cexpGen();
        }

        now = 1;
        cexpGen();
    }
}