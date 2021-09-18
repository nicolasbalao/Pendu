#include <stdio.h>
#include <stdlib.h>

//headers
#include "../headers/gameLoop.h"

int main(int argc, char *argv[])
{
    int play = 1;
    char answer = 0;
    int nbrePlayer = 0;
    int gameModeChoise = 0;

    //SET UP
    printf("Bienvenue dans le pendu ! \n\n");
    printf("Combien de joeur: ");
    scanf("%d", &nbrePlayer);

    while (play == 1)
    {

        //MENU GAME MODE
        printf("1. VS IA \n");
        printf("2. Player vs Player \n");
        scanf("%d", &gameModeChoise);

        switch (gameModeChoise)
        {
        case 1:
            game(1, nbrePlayer);
            break;
        case 2:
            game(2, nbrePlayer);
            break;
        default:
            printf("Mauvais choix \n");
        }

        //replay
        printf("Replay (y/n): ");
        scanf("%c", &answer);
        if (answer != 'y')
        {
            play = 0;
        }
    }
    return 0;
}