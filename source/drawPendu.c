#include <stdio.h>

void drawPendu(int nbreVie)
{
    switch (nbreVie)
    {
    case 9:
        printf(" |_________\n");
        break;
    case 8:
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |_________\n");
        break;
    case 7:
        printf(" |------\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |_________\n\n");
        break;
    case 6:
        printf(" |------\n");
        printf(" |     |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |_________\n\n");
        break;
    case 5:
        printf(" |------\n");
        printf(" |     |\n");
        printf(" |     O \n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |_________\n\n");
        break;
    case 4:
        printf(" |------\n");
        printf(" |     |\n");
        printf(" |     O \n");
        printf(" |     | \n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |_________\n\n");
        break;
    case 3:
        printf(" |------\n");
        printf(" |     |\n");
        printf(" |     O \n");
        printf(" |    /| \n");
        printf(" |\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |_________\n\n");
        break;
    case 2:
        printf(" |------\n");
        printf(" |     |\n");
        printf(" |     O \n");
        printf(" |    /|\\ \n");
        printf(" |     -\n");
        printf(" |\n");
        printf(" |\n");
        printf(" |_________\n\n");
        break;
    case 1:
        printf(" |------\n");
        printf(" |     |\n");
        printf(" |     O \n");
        printf(" |    /|\\ \n");
        printf(" |     -   \n");
        printf(" |      \\  \n");
        printf(" |\n");
        printf(" |_________\n\n");
        break;
    case 0:
        printf(" |------\n");
        printf(" |     |\n");
        printf(" |     O \n");
        printf(" |    /|\\ \n");
        printf(" |     -   \n");
        printf(" |    / \\  \n");
        printf(" |\n");
        printf(" |_________\n\n");

        break;
    default:
        printf("Pas encore juger \n\n");
    }
}