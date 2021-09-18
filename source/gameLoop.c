#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/player.h"
#include "../headers/manipString.h"
#include "../headers/manipFile.h"
#define TAILLE_MAX 20

//PROTOTYPE
void initPlayer(Player *c, int nbrePlayer);

void game()
{
    //Declaration des variable
    char mysteryWord[TAILLE_MAX] = "";
    int nbrePlayer = 0;
    //init Structure
    Player player[TAILLE_MAX];

    //Choose Random Word
    chooseWord(mysteryWord, TAILLE_MAX);
    // Replace \n to \0

    int sizeMysteryWord = strlen(mysteryWord) - 1;
    replaceReturnLine(mysteryWord, sizeMysteryWord);

    //SET UP
    printf("Bienvenue dans le pendu ! \n\n\n");
    printf("Combien de joeur: ");
    scanf("%d", &nbrePlayer);

    //INIT letterfind a *****

    for (int i = 0; i < nbrePlayer; i++)
    {
        initLetterFind(player[i].playerWord, sizeMysteryWord);
    }

    //init Player coup
    initPlayer(player, nbrePlayer);

    //Game loop
    int win = 0;
    do
    {
        for (int i = 0; i < nbrePlayer; i++)
        {

            printf("\e[1;1H\e[2J"); // For clear the console

            printf("TOUR JOUEUR %d \n\n", i + 1);
            player[i].letter = 0;
            //Trame du jeux
            printf("Il vous reste %d coup a jouer \n", player[i].nbreCoup);
            printf("Quelle est le mot secret: ");
            printTableau(player[i].playerWord, sizeMysteryWord);
            printf("\n");

            printf("Joeur %d roposer un letter: ", i + 1);
            player[i].letter = readCaractere(); // focntion == scanf mais on exclus le \n char
            printf("\n");
        }
        for (int i = 0; i < nbrePlayer; i++)
        {
            testLetterInWord(player[i].letter, mysteryWord, player[i].playerWord, sizeMysteryWord, &player[i].nbreCoup); // prendre chaque letter des 2 tableau et le compare si trouver ajoute a letter find
        }
        for (int i = 0; i < nbrePlayer; i++)
        {
            win = testWin(mysteryWord, player[i].playerWord, sizeMysteryWord);
            if (win == 1)
            {
                break;
            }
        }

    } while (win != 1);

    for (int i = 0; i < nbrePlayer; i++)
    {
        if (player[0].nbreCoup == 0)
        {
            printf("Vous avez perdu dommage");
        }
        else
        {
            printf("Vous avez trouve le mot: %s GG Player %d! \n\n\n", mysteryWord, i + 1);
            break;
        }
    }
}

void initPlayer(Player *c, int nbrePlayer)
{
    for (int i = 0; i < nbrePlayer; i++)
    {
        c[i].nbreCoup = 10;
    }
}