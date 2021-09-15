#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define

void chooseWord(char *mysteryWord, int TAILLE_MAX)
{
    FILE *wordList = NULL;
    wordList = fopen("../tmp/listOfWord.txt", "r");
    int nbreLine = 0;
    char letterCurrent = 0;
    int lineChoosen = 0;
    int *pointeurLine = &nbreLine;

    if (wordList != NULL)
    {
        // GET NUMBER OF LINE
        do
        {
            letterCurrent = fgetc(wordList);
            if (letterCurrent == '\n')
            {
                (*pointeurLine)++; //pour incrémenter les pointeurs
            }

        } while (letterCurrent != EOF);
        //Deplace cursor to the start of file
        rewind(wordList);

        // Random value for Random Line
        if (nbreLine != 0)
        {
            srand(time(NULL)); // reset the seed
            lineChoosen = rand() % nbreLine;
            printf("lineChoosen: %d \n", lineChoosen);
        }
        else
        {
            printf("Error File void \n");
        }

        //Get ligne (word) of lineChoosen*
        for (int i = 0; i < lineChoosen; i++)
        {
            fgets(mysteryWord, TAILLE_MAX, wordList);
        }
    }
    else
    {
        printf("Error Open File \n");
        exit(0);
    }
}