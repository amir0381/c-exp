#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/tinyexpr.h"

void cexpGen();

char c_exp[18] = "1";
char expressions[2] = {'+', '-'};
int now = 0;

int main()
{
    cexpGen();
    printf("%s", c_exp);
    return 0;
}

void cexpGen()
{
    for (; now < 3; now++)
    {
        if (now == 0)
        {
            c_exp[strlen(c_exp)] = expressions[0];
            c_exp[strlen(c_exp)] = '\0';

            c_exp[strlen(c_exp)] = ((c_exp[strlen(c_exp) - 2]) + 1);
            c_exp[strlen(c_exp)] = '\0';

            now++;

            if (c_exp[(strlen(c_exp) - 1)] == '9')
            {
                if (te_interp(c_exp, 0) == 100)
                {
                    int i = 1;
                    printf("%c   %s\n", i, c_exp);
                    i++;
                }
            }

            cexpGen();
        }

        if (now == 1)
        {
            c_exp[strlen(c_exp)] = expressions[1];
            c_exp[strlen(c_exp)] = '\0';

            c_exp[strlen(c_exp)] = ((c_exp[strlen(c_exp) - 2]) + 1);
            c_exp[strlen(c_exp)] = '\0';

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
            c_exp[strlen(c_exp)] = ((c_exp[strlen(c_exp) - 1]) + 1);
            c_exp[strlen(c_exp)] = '\0';

            if (c_exp[(strlen(c_exp) - 1)] == '9')
            {
                if (te_interp(c_exp, 0) == 100)
                {
                    int i = 1;
                    printf("%c   %s\n", i, c_exp);
                    i++;
                }
            }

            cexpGen();
        }
    }
}
