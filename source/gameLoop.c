#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headers/drawPendu.h"
#include "../headers/player.h"
#include "../headers/manipString.h"
#include "../headers/manipFile.h"
#define TAILLE_MAX 20

//PROTOTYPE

void clearBuffer();

void game(int gamesMode, int nbrePlayer)
{
    //Declaration des variable
    char mysteryWord[TAILLE_MAX] = "";
    int readMysteryWord = 0;
    //init Structure
    Player player[TAILLE_MAX];

    //ask name to players and coup = 10
    initPlayer(player, nbrePlayer);

    //CLEAR BUFFER
    clearBuffer();

    //initPlayer NAME AND COUP

    //GAME MODE
    if (gamesMode == 1)
    {
        //Choose Random Word
        chooseWord(mysteryWord, TAILLE_MAX);

        // Replace \n to \0
        int sizeMysteryWord = strlen(mysteryWord) - 1;
        replaceReturnLine(mysteryWord);
    }

    if (gamesMode == 2)
    {
        int playerChoosen;
        //Random player
        srand(time(NULL)); // reset the seed
        playerChoosen = rand() % nbrePlayer;

        //update nbrePlayer
        updatePlayerStatu(player, &nbrePlayer, playerChoosen);

        printf("%s choose a word please: ", player[playerChoosen].name);
        fgets(mysteryWord, TAILLE_MAX, stdin);
        replaceReturnLine(mysteryWord);
    }

    int sizeMysteryWord = strlen(mysteryWord);

    //INIT letterfind a *****

    // for (int i = 0; i < nbrePlayer; i++)
    // {
    //     initLetterFind(player[i].playerWord, sizeMysteryWord, mysteryWord);
    // }

    //init Player word
    PlayerWord(player, nbrePlayer, sizeMysteryWord, mysteryWord);

    //Game loop
    int play = 1;
    int win = 0;
    int playerLoose = 0;
    do
    {
        for (int i = 0; i < nbrePlayer; i++)
        {

            //test if player is a player or not
            if (player[i].statu != 0)
            {
                break;
            }

            printf("\e[1;1H\e[2J"); // For clear the console

            printf("TOUR DE %s \n\n", player[i].name);
            player[i].letter = 0;

            drawPendu(player[i].nbreCoup);
            printf("\n\n");

            //Trame du jeux
            printf("Il vous reste %d coup a jouer \n", player[i].nbreCoup);
            printf("Quelle est le mot secret: ");
            printTableau(player[i].playerWord, sizeMysteryWord);
            printf("\n");

            printf("%s roposer un letter: ", player[i].name);
            player[i].letter = readCaractere(); // focntion == scanf mais on exclus le \n char
            printf("\n");

            testLetterInWord(player[i].letter, mysteryWord, player[i].playerWord, sizeMysteryWord, &player[i].nbreCoup); // prendre chaque letter des 2 tableau et le compare si trouver ajoute a letter find

            win = testWin(mysteryWord, player[i].playerWord, sizeMysteryWord);
            if (win == 1)
            {
                play = 0;
                printf("Bravo %s a gagner!! \n", player[i].name);
                break;
            }
            if (player[i].nbreCoup == 0)
            {
                drawPendu(player[i].nbreCoup);
                printf("%s est mort PENDU !! \n", player[i].name);
                player[i].statu = 1;
                playerLoose++;
            }
        }
        // for (int i = 0; i < nbrePlayer; i++)
        // {
        //     testLetterInWord(player[i].letter, mysteryWord, player[i].playerWord, sizeMysteryWord, &player[i].nbreCoup); // prendre chaque letter des 2 tableau et le compare si trouver ajoute a letter find
        // }
        // //test Win or Loose
        // for (int i = 0; i < nbrePlayer; i++)
        // {
        //     win = testWin(mysteryWord, player[i].playerWord, sizeMysteryWord);
        //     if (win == 1)
        //     {
        //         play = 0;
        //         printf("Bravo %s a gagner!! \n", player[i].name);
        //         break;
        //     }
        //     if (player[i].nbreCoup == 0)
        //     {
        //         drawPendu(player[i].nbreCoup);
        //         printf("%s est mort PENDU !! \n", player[i].name);
        //         player[i].statu = 1;
        //         playerLoose++;
        //     }
        // }

    } while (play == 1 && playerLoose != nbrePlayer);
}

void clearBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}