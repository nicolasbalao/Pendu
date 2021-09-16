#include <stdio.h>
#include <stdlib.h>

//headers
#include "../headers/gameLoop.h"

int main(int argc, char *argv[])
{
    int play = 1;
    char answer = 0;

    while (play == 1)
    {
        game();
        printf("Replay (y/n): ");
        scanf("%c", &answer);
        if (answer != 'y')
        {
            play = 0;
        }
    }
    return 0;
}