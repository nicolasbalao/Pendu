#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}

int main(int argc, char *argv[])
{
    char nom[20];
    printf("Quelle est votre nom: ");
    lire(nom, 20);
    printf("Votre nom est: %s", nom);

    return 0;
}
