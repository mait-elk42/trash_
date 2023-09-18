#include "printer.cpp"
#include<stdlib.h>
using namespace PRINTER;
#define clr system("clear");

static int input;

class player{
public:
    char * player_name;
    char player_symbole;
    colors_list player_symbole_color;
    int points = 0;
    player(char *player_name, char player_symbole,colors_list player_symbole_color)
    {
        this->player_name = player_name;
        this->player_symbole = player_symbole;
        this->player_symbole_color = player_symbole_color;
    }
};
class nsx_GAME_ROUND {
private:
    int i = 0;
    int its_me_player = 1;
    int input;
    int playing = 0;
    char *table = (char *) malloc(9);
    player *player1;
    player *player2;
public:
    nsx_GAME_ROUND(player *plr1,player *plr2)
    {
        this->player1 = plr1;
        this->player2 = plr2;
    
        i = 0;
        while(i < 9)
            table[i++] = i + 49;
    }
    int check_table_is_avaiable()
    {
        i = 0;
        while(i < 9)
            if(table[i] >= '0' && table[i] <= '9')
                return 1;
            else
                i++;
        return 0;
    }
    int check_if_this_plr_winner(char *table,char plrc)
    {
    if (
        (table[0] == plrc && table[4] == plrc && table[8] == plrc) || // Diagonal from top-left to bottom-right
        (table[2] == plrc && table[4] == plrc && table[6] == plrc) || // Diagonal from top-right to bottom-left
        (table[0] == plrc && table[1] == plrc && table[2] == plrc) || // Top row
        (table[3] == plrc && table[4] == plrc && table[5] == plrc) || // Middle row
        (table[6] == plrc && table[7] == plrc && table[8] == plrc) || // Bottom row
        (table[0] == plrc && table[3] == plrc && table[6] == plrc) || // Left column
        (table[1] == plrc && table[4] == plrc && table[7] == plrc) || // Middle column
        (table[2] == plrc && table[5] == plrc && table[8] == plrc)    // Right column
        )
            return 1;
        return 0;
    }
    void nsX_StartGameLoop()
    {
        clr;
        playing = 1;
        while(playing)
        {
            print_table();
            putstr((its_me_player == 1) ? "\nPLAYER 1 PLAYING..." : "\nPLAYER 2 PLAYING...");
            putstr("\nENTER [1-9] NUM XD:\n > ");
            getinput(&input);
            if(input-48 == 0)
            {
                    putstr("ARE YOU SURE WANT EXIT! [Y-N]\n > ");
                    int resp = 1;
                    while(resp)
                    {
                        getinput(&input);
                        if(input != '\n')
                        {
                            clr;
                            if(input == 'Y')
                                playing = resp = 0;
                            else if(input == 'N')
                                break;
                            putstr("\n!!!!!ENTER FUCKING VALID COMMAND :>\n");
                            putstr("ARE YOU SURE WANT EXIT! [Y-N]\n > ");
                        }
                    }

            }  
            if(input >= '0' && input <= '9')
            {
                    if(table[input-48-1] >= '0' && table[input-48-1] <= '9')
                    {
                        if(its_me_player == 1)
                        {
                            table[input-49] = player1->player_symbole;
                            its_me_player = 2;
                        }else if(its_me_player == 2)
                        {
                            table[input-49] = player2->player_symbole;
                            its_me_player = 1;
                        }
                    }
                    else
                    {
                        //the place already used :> 
                    }
            }
            clr;
            if(check_if_this_plr_winner(table,get_player((its_me_player == 2) ? 1 : 2)->player_symbole))
            {
                //putstr(___colors_list[get_player(its_me_player)->player_symbole_color]);
                putstr((its_me_player == 2) ? "PLAYER 1 WINNER!!" : "PLAYER 2 WINNER!!");// reversed to fix check winner XD
                //putstr("\033[1;0m");
                playing = 0;
            }
        }
    }
    void print_table()
    {
    int i = 0;
    while(i < 9)
        {
            if(table[i] == player1->player_symbole)
                {putstr(___colors_list[player1->player_symbole_color]);
                putchar(table[i]);
                putstr("\033[1;0m");}
            else if(table[i] == player2->player_symbole)
                {putstr(___colors_list[player2->player_symbole_color]);
                putchar(table[i]);
                putstr("\033[1;0m");}
            else
                putchar(table[i]);
            putchar(' ');
            if(i == 2 || i == 5 || i == 8)
                putchar('\n');
            i++;
        }
    }
    char *getTable()
    {
        return table;
    }
    player  *get_player(int num)
    {
        if(num == 1) 
            return player1;
        else
        if(num == 2)
            return player2;
        else
            return 0;
    }
    void nsX_endGame()
    {
        free(table);
    }
};
nsx_GAME_ROUND *nsX_Init(player *player1,player *player2)
{
    int i = 0;
    nsx_GAME_ROUND *round = new nsx_GAME_ROUND(player1,player2);
    if(round == 0)
        return 0;
    return round;
}

