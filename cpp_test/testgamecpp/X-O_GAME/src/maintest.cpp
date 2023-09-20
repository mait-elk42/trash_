#include "nsX_XO.cpp"
using namespace PRINTER;

void OnPlayerWin(player *winner)
{
    putstr("player winner!!!\n");
    putstr(winner->player_name);
    putchar('\n');
}
void OnPlayersDraw()
{
    putstr("players draw!!!\n");
    putchar('\n');
}
int main()
{
    player *player1 = new player("BOT_1",'&',Blue,true);
    player *bot = new player("BOT_2",'@',Red,true);
    nsx_GAME_ROUND* round = nsX_Init(player1,bot);
    round->nsX_Listen_OnPlayerWinner(&OnPlayerWin,false);
    round->nsX_Listen_OnPlayersDraw(&OnPlayersDraw,true);
    round->nsX_StartGameLoop();
    round->nsX_endGame();
}
