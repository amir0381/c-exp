#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tinyexpr.h"

char *cexpGen();

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
        if (now == 1)
        {
            c_exp[len++] = expressions[0];
            c_exp[len] = '\0';

            c_exp[len++] = ((c_exp[strlen(c_exp) - 2]) + 1);
            c_exp[len] = '\0';

            now++;

            cexpGen();
        }

        if (now == 2)
        {
            c_exp[len++] = expressions[1];
            c_exp[len] = '\0';

            c_exp[len++] = ((c_exp[strlen(c_exp) - 2]) + 1);
            c_exp[len] = '\0';

            now++;
            cexpGen();
        }

        if (now == 3)
        {
            c_exp[len++] = ((c_exp[strlen(c_exp) - 1]) + 1);
            c_exp[len] = '\0';

            if (c_exp[(strlen(c_exp) - 1)] == '9')
            {
                if (te_interp(c_exp, 0) == 100)
                {
                    int i = 1;
                    printf("%c   %s", i, c_exp);
                    i++;
                }
            }

            now = 1;
            cexpGen();
        }
    }
}