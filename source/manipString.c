#include <stdio.h>
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

void initLetterFind(char *inputWord, int sizeTableau)
{
    for (int i = 0; i < sizeTableau; i++)
    {
        inputWord[i] = '*';
    }
}

int testWin(char *mysteryWord, char *playWord, int sizeTableau)
{
    for (int i = 0; i < sizeTableau; i++)
    {
        if (mysteryWord[i] != playWord[i])
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

void replaceReturnLine(char *chaine, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (chaine[i] == '\n')
        {
            chaine[i] = '\0';
        }
    }
}