#include "nsX_XO.cpp"

using namespace PRINTER;
void OnPlayerWin(player *winner)
{
    putstr("player winner!!!\n");
    putchar(winner->id+48);
    putchar('\n');
}
void OnPlayersDraw()
{
    putstr("players draw!!!\n");
    putchar('\n');
}
int main()
{
    player *player1 = new player("elkadi",'&',Blue);
    player *player2 = new player("abouqas",'@',Red);
    nsx_GAME_ROUND* round = nsX_Init(player1,player2);
    round->nsX_Listen_OnPlayerWinner(&OnPlayerWin,false);
    round->nsX_Listen_OnPlayersDraw(&OnPlayersDraw,true);
    round->nsX_StartGameLoop();
    round->nsX_endGame();
}
