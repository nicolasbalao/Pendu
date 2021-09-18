//typedef
typedef struct Player Player;
void updatePlayerStatu(Player *asPlayer, int *nbrePlayer, int playerChoose);
void initPlayer(Player *asPlayer, int nbrPlayer);
void PlayerWord(Player *c, int nbrePlayer, int lenght, char *mysteryWord);

struct Player
{
    int nbreCoup;
    int statu; // 1 == Player who choose word OR player who lost
    char name[20];
    char letter;
    char playerWord[20];
};