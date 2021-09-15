#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//headers
#include "../headers/manipString.h"

int main(int argc, char *argv[])
{
    //Declaration des variable
    char mysteryWord[] = "marron";
    int sizeMysteryWord = strlen(mysteryWord);
    char inputWord[strlen(mysteryWord)];
    int nbreCoup = 10;
    char inputChar = 0;

    initInputWord(inputWord, sizeMysteryWord);
    printTableau(inputWord, sizeMysteryWord);

    //SET UP
    printf("Bienvenue dans le pendu ! \n\n\n");

    //Game loop
    while (testWin(mysteryWord, inputWord, sizeMysteryWord) == 1 && nbreCoup != 0)
    {
        inputChar = 0;
        //Trame du jeux
        printf("Il vous reste %d coup a jouer \n", nbreCoup);
        printf("Quelle est le mot secret: ");
        printTableau(inputWord, sizeMysteryWord);
        printf("\n");

        printf("Proposer un letter: ");
        inputChar = lireCaractere();
        printf("\n");

        testLetterInWord(inputChar, mysteryWord, inputWord, sizeMysteryWord, &nbreCoup);
    }

    if (nbreCoup == 0)
    {
        printf("Vous avez perdu dommage");
    }
    else
    {
        printf("Vous avez gangner GG! \n\n\n");
    }

    return 0;
}