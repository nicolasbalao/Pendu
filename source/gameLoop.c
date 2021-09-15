#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/manipString.h"
#include "../headers/manipFile.h"
#define TAILLE_MAX 20
void game()
{
    //Declaration des variable
    char mysteryWord[TAILLE_MAX] = "";
    char letterFind[strlen(mysteryWord)];
    int nbreCoup = 10;
    char letter = 0;

    //Choose Random Word
    chooseWord(mysteryWord, TAILLE_MAX);
    // Replace \n to \0

    int sizeMysteryWord = strlen(mysteryWord) - 1;
    replaceReturnLine(mysteryWord, sizeMysteryWord);

    //SET UP
    printf("Bienvenue dans le pendu ! \n\n\n");

    //INIT letterfind a *****
    initLetterFind(letterFind, sizeMysteryWord);

    //Game loop
    while (testWin(mysteryWord, letterFind, sizeMysteryWord) == 1 && nbreCoup != 0)
    {

        letter = 0;
        //Trame du jeux
        printf("Il vous reste %d coup a jouer \n", nbreCoup);
        printf("Quelle est le mot secret: ");
        printTableau(letterFind, sizeMysteryWord);
        printf("\n");

        printf("Proposer un letter: ");
        letter = readCaractere(); // focntion == scanf mais on exclus le \n char
        printf("\n");

        testLetterInWord(letter, mysteryWord, letterFind, sizeMysteryWord, &nbreCoup); // prendre chaque letter des 2 tableau et le compare si trouver ajoute a letter find
    }

    if (nbreCoup == 0)
    {
        printf("Vous avez perdu dommage");
    }
    else
    {

        printf("Vous avez trouve le mot: %s GG! \n\n\n", mysteryWord);
    }
}