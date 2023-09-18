#include "nsX_XO.cpp"

using namespace PRINTER;
int main()
{
    player *player1 = new player("elkadi",'&',Blue);
    player *player2 = new player("abouqas",'@',White);
    nsx_GAME_ROUND* round = nsX_Init(player1,player2);
    round->nsX_StartGameLoop();
    
    round->nsX_endGame();
}
