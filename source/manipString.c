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

void testLetterInWord(char letter, char *mysteryWord, char *InputWord, int sizeTableau, int *coup)
{
    int winRound = 0;
    for (int i = 0; i < sizeTableau; i++)
    {
        if (letter == mysteryWord[i])
        {
            InputWord[i] = letter;
            winRound = 1;
        }
    }
    if (winRound == 0)
    {
        *coup = *coup - 1;
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
