#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../headers/player.h"

void initPlayer(Player *asPlayer, int nbrPlayer)
{

    for (int i = 0; i < nbrPlayer; i++)
    {

        asPlayer[i].nbreCoup = 10;
        asPlayer[i].statu = 0;
        printf("Player %d name: ", i + 1);
        scanf("%s", asPlayer[i].name);
    }
}

void updatePlayerStatu(Player *asPlayer, int playerChoose)
{
    asPlayer[playerChoose].statu = 2;
}

void PlayerWord(Player *c, int nbrePlayer, int lenght, char *mysteryWord)
{
    //boucle joeur
    for (int i = 0; i < nbrePlayer; i++)
    {
        c[i].nbreCoup = 10;
        //boucle playerWord
        for (int j = 0; j < lenght; j++)
        {
            if (mysteryWord[j] == mysteryWord[0])
            {
                c[i].playerWord[j] = mysteryWord[j];
            }
            else
            {
                c[i].playerWord[j] = '*';
            }
        }
    }
}