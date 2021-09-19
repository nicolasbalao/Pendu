//typedef
typedef struct Player Player;
void updatePlayerStatu(Player *asPlayer, int playerChoose);
void initPlayer(Player *asPlayer, int nbrPlayer);
void PlayerWord(Player *c, int nbrePlayer, int lenght, char *mysteryWord);

struct Player
{
    int nbreCoup;
    int statu; // 0 = player who play the game 1= player dead  2 = player who choose the word
    char name[20];
    char letter;
    char playerWord[20];
};