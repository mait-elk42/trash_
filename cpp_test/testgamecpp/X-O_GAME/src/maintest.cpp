#include "nsX_XO.cpp"
#include <iostream>
#include <ctime>
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
    player *player1 = new player("elkadi",'&',Blue,false);
    player *bot = new player("abouqas",'@',Red,false);
    nsx_GAME_ROUND* round = nsX_Init(player1,bot);
    round->nsX_Listen_OnPlayerWinner(&OnPlayerWin,false);
    round->nsX_Listen_OnPlayersDraw(&OnPlayersDraw,true);
    //round->nsX_StartGameLoop();
    putnbr(-2147483647);
    // while(i)
    // {
    //     if(tmp != rand())
    //     {
    //         putnbr(((tmp % 10) == 0) ? 1 : (tmp % 10) );
    //         putchar('\n');
    //         tmp = rand();
    //         i--;
    //     }
    // }
    round->nsX_endGame();
}
