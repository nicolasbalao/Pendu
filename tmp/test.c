#include <stdio.h>
#include <stdlib.h>

typedef struct Test Test;

struct Test
{
    int lol;
    char txt;
};

int main(int argc, char *argv[])
{
    Test stp[2];
    initStructs(stp);

    for (int i = 0; i < 2; i++)
    {
        printf("stp[%d] lol: %d \n", i + 1, stp[i].lol);
        printf("stp[%d] txt: %c \n", i + 1, stp[i].txt);
    }

    return 0;
}

void initStructs(Test *s)
{
    for (int i = 0; i < 2; i++)
    {
        s[i].lol = 3;
        s[i].txt = 'c';
    }
}