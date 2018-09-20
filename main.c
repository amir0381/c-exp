#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/tinyexpr.h"

void cexpGen();

char c_exp[18] = "1";
char expressions[3] = {'+', '-'};
int now = 0;

int main()
{
    cexpGen();
    printf("%s", c_exp);
    return 0;
}

void cexpGen()
{
    size_t len = strlen(c_exp);

    for (; now < 3; now++)
    {
        if (now == 0)
        {
            c_exp[len++] = expressions[0];
            c_exp[len++] = '\0';

            c_exp[len++] = ((c_exp[strlen(c_exp) - 2]) + 1);
            c_exp[len++] = '\0';

            now++;

            if (c_exp[(strlen(c_exp) - 1)] == '9')
            {
                if (te_interp(c_exp, 0) == 100)
                {
                    int i = 1;
                    printf("%c   %s\n", i, c_exp);
                    i++;
                }

                continue;
            }

            char c_exptmp[] = c_exp;

            cexpGen();

            c_exp = c_exptmp;
        }

        if (now == 1)
        {
            c_exp[len++] = expressions[1];
            c_exp[len++] = '\0';

            c_exp[len++] = ((c_exp[strlen(c_exp) - 2]) + 1);
            c_exp[len++] = '\0';

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

            char c_exptmp[] = c_exp;

            cexpGen();

            c_exp = &c_exptmp;
        }

        if (now == 2)
        {
            c_exp[len++] = ((c_exp[strlen(c_exp) - 1]) + 1);
            c_exp[len++] = '\0';

            if (c_exp[(strlen(c_exp) - 1)] == '9')
            {
                if (te_interp(c_exp, 0) == 100)
                {
                    int i = 1;
                    printf("%c   %s\n", i, c_exp);
                    i++;
                }
            }

            char c_exptmp[] = c_exp;

            cexpGen();

            c_exp = c_exptmp;
        }
    }
}
