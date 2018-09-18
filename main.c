#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * cexpGen ();

char c_exp[] = "1";
char expressions[2] = {'+', '-'};

int main()
{
    cexpGen();
    printf("%s", c_exp);
    return 0;
}

char * cexpGen () {
    int now = 1;
    while (atoi(c_exp[ strlen(c_exp) - 1 ]) > 10)
    {
        if (atoi(c_exp[ strlen(c_exp) - 1 ]) == '+' || atoi(c_exp[ strlen(c_exp) - 1 ]) == '-') {
            strcat(c_exp, ( ( atoi( c_exp[ strlen(c_exp) - 2 ] )) + 1 ));
            continue;
        }
        if (now = 1) {
        strcat(c_exp, expressions[1]);
        now++;
        cexpGen();
        }
        if (now = 2) {
        strcat(c_exp, expressions[2]);
        now++;
        cexpGen();
        }
        if (now = 3) {
        strcat(c_exp, ( ( atoi(c_exp[ strlen(c_exp) - 1 ])) ) + 1 );
        }
    }
}