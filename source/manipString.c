#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/player.h"

void printTableau(char *tableau, int sizeTableau)
{
    for (int i = 0; i < sizeTableau; i++)
    {
        printf("%c", tableau[i]);
    }
    printf("\n");
}

int testWin(char *mysteryWord, char *playerWord, int sizeTableau)
{
    for (int i = 0; i < sizeTableau; i++)
    {
        if (mysteryWord[i] != playerWord[i])
        {
            return 0;
        }
    }
    return 1;
}

void testLetterInWord(Player *asPlayer, char *mysteryWord, int sizeTableau)
{
    int winRound = 0;
    for (int i = 0; i < sizeTableau; i++)
    {
        if (asPlayer->letter == mysteryWord[i])
        {
            asPlayer->playerWord[i] = mysteryWord[i];
            winRound = 1;
        }
    }
    if (winRound == 0)
    {
        asPlayer->nbreCoup -= 1;
        asPlayer->letterWrong[asPlayer->indexLetterWrong] = asPlayer->letter;
        asPlayer->indexLetterWrong++;

        // *coup = *coup - 1;
    }
}

char readCaractere()
{
    char caractere = getchar();
    while (getchar() != '\n') //lit tous les caractère jusqu'a \n
        ;
    return caractere;
}

void replaceReturnLine(char *chaine)
{
    for (int i = 0; i < strlen(chaine); i++)
    {
        if (chaine[i] == '\n')
        {
            chaine[i] = '\0';
        }
    }
}
