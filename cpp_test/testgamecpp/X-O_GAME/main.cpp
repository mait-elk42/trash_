#include "src/nsX_XO.cpp"

void OnPlayerWin(player *winner)
{
    //putstr("player winner!!!\n");
    //putstr(winner->player_name);
    putchar('\n');
}
void OnPlayersDraw()
{
    //putstr("players draw!!!\n");
    putchar('\n');
}
int main(int ac,char *av[])
{
    clr;
    PUTLOGO();
    nsx_GAME_ROUND* round;
    player *player1;
    player *player2;
    player *bot;
    int rounds_count;
    player1 = new player((char *)"PLAYER_1",'X',Blue,false);
    player2 = new player((char *)"PLAYER_2",'O',Red,false);
    //INITIALIZAION PLAYERS FROM ARGV :av[2 && 3]
    if(ac > 1)
    {
        if(ac > 1)
            player1 = new player((char *)av[1],'X',Blue,false);
        if(ac > 2)
            player2 = new player((char *)av[2],'O',Red,false);
        if(ac > 3)
            rounds_count = av[3][0]-48;
        
    }
    bot = new player((char *)"nsX_BOT",'@',Green,true);
    char _name[10];
    int inpuut;
    putstr("WELCOME :) \n");
        clr;
        PUTLOGO();
        putstr("-ENTER [P] TO ENTER PVP MODE \n -ENTER [C] TO ENTER PVC MODE >\n> ");
        getinput(&inpuut);
        if(inpuut == 'P')
        {
            clr;
            round = nsX_Init(player1,player2);
        }
        if(inpuut == 'C')
        {
            clr;
            round = nsX_Init(player1,bot);
        }
        round->nsX_Listen_OnPlayerWinner(&OnPlayerWin,false);
        round->nsX_Listen_OnPlayersDraw(&OnPlayersDraw,true);
        round->nsX_StartGameLoop();
        round->nsX_endGame();
}
