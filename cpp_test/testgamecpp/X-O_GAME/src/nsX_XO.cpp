#include "nsX_String.cpp"
using namespace PRINTER;
#define clr system("clear");
#define true 1
#define false 0
#define clearcolor putstr("\033[1;0m");
static int input;

class player{
public:
    int is_bot;
    int id;
    char * player_name;
    char player_symbole;
    colors_list player_symbole_color;
    int points = 0;
    player(char *player_name, char player_symbole,colors_list player_symbole_color,int is_bot)
    {
        this->is_bot = is_bot;
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

    void (*OnPlayerWin)(player *winner);
    int stop_default_opw_func = 1;

    void (*OnPlayersDraw)();
    int stop_default_opd_func = 1;
public:
    nsx_GAME_ROUND(player *plr1,player *plr2)
    {
        this->player1 = plr1;
        this->player2 = plr2;
    
        i = 0;
        while(i < 9)
            table[i++] = i + 49;
    }
    void nsX_Listen_OnPlayerWinner(void (*func)(player *winner),int stop_default_func)
    {
        OnPlayerWin = func;
        this->stop_default_opw_func = stop_default_func;
    }
    void nsX_Listen_OnPlayersDraw(void (*func)(),int stop_default_func)
    {
        OnPlayersDraw = func;
        this->stop_default_opd_func = stop_default_func;
    }
private:
    void _change_player()
    {
        its_me_player = (its_me_player == 2) ? 1 : 2;
    }
public:
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
        (table[0] == plrc && table[4] == plrc && table[8] == plrc) ||
        (table[2] == plrc && table[4] == plrc && table[6] == plrc) || 
        (table[0] == plrc && table[1] == plrc && table[2] == plrc) || 
        (table[3] == plrc && table[4] == plrc && table[5] == plrc) || 
        (table[6] == plrc && table[7] == plrc && table[8] == plrc) || 
        (table[0] == plrc && table[3] == plrc && table[6] == plrc) || 
        (table[1] == plrc && table[4] == plrc && table[7] == plrc) || 
        (table[2] == plrc && table[5] == plrc && table[8] == plrc)    
        )
            return 1;
        return 0;
    }
    void print_table()
    {
        int i = 0;
        clearcolor;
        putstr(___colors_list[get_player(its_me_player)->player_symbole_color]);
        putstr("-------------\n");
        while(i < 9)
            {
                putstr("| ");
                if(table[i] == player1->player_symbole || table[i] == player2->player_symbole)
                    putstr(___colors_list[(table[i] == player1->player_symbole) ? player1->player_symbole_color : player2->player_symbole_color]);
                putchar(table[i]);
                putstr(___colors_list[get_player(its_me_player)->player_symbole_color]);
                putchar(' ');
                if(i == 2 || i == 5 || i == 8)
                    if(i == 2 || i == 5)
                        putstr("|\n----+---+----\n");
                    if(i == 8)
                        putstr("|\n-------------\n");
                i++;
            }
        clearcolor;
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
int is_avaiable_place(char c)
    {
        return (c >= '1' && c <= '9');
    }
int myenemy_very_close_to_win(player *enemy)
    {
        char plrc = enemy->player_symbole;
        if (table[0] == plrc && table[4] == plrc && is_avaiable_place(table[8]))
            return is_avaiable_place(table[8]-'0');
        else
        if(table[0] == plrc && is_avaiable_place(table[4]) && table[8] == plrc)
            return is_avaiable_place(table[4]-'0');
        else
        if(is_avaiable_place(table[0]) && table[4] == plrc && table[8] == plrc)
            return is_avaiable_place(table[0]-'0');

        


        if (table[2] == plrc && table[4] == plrc && is_avaiable_place(table[6]))
            return is_avaiable_place(table[6]-'0');
        else
        if(table[2] == plrc && is_avaiable_place(table[4]) && table[6] == plrc)
            return is_avaiable_place(table[4]-'0');
        else
        if(is_avaiable_place(table[2]) && table[4] == plrc && table[6] == plrc)
            return is_avaiable_place(table[2]-'0');
        


        if (table[0] == plrc && table[1] == plrc && is_avaiable_place(table[2]))
            return is_avaiable_place(table[2]-'0');
        else
        if(table[0] == plrc && is_avaiable_place(table[1]) && table[2] == plrc)
            return is_avaiable_place(table[1]-'0');
        else
        if(is_avaiable_place(table[0]) && table[1] == plrc && table[2] == plrc)
            return is_avaiable_place(table[0]-'0');
        


        if (table[3] == plrc && table[4] == plrc && is_avaiable_place(table[5]))
            return is_avaiable_place(table[5]-'0');
        else
        if(table[3] == plrc && is_avaiable_place(table[4]) && table[5] == plrc)
            return is_avaiable_place(table[4]-'0');
        else
        if(is_avaiable_place(table[3]) && table[4] == plrc && table[5] == plrc)
            return is_avaiable_place(table[3]-'0');
        


        if (table[6] == plrc && table[7] == plrc && is_avaiable_place(table[8]))
            return is_avaiable_place(table[8]-'0');
        else
        if(table[6] == plrc && is_avaiable_place(table[7]) && table[8] == plrc)
            return is_avaiable_place(table[7]-'0');
        else
        if(is_avaiable_place(table[6]) && table[7] == plrc && table[8] == plrc)
            return is_avaiable_place(table[6]-'0');
        


        if (table[0] == plrc && table[3] == plrc && is_avaiable_place(table[6]))
            return is_avaiable_place(table[0]-'0');
        else
        if(table[0] == plrc && is_avaiable_place(table[3]) && table[6] == plrc)
            return is_avaiable_place(table[3]-'0');
        else
        if(is_avaiable_place(table[0]) && table[3] == plrc && table[6] == plrc)
            return is_avaiable_place(table[6]-'0');



        if (table[1] == plrc && table[4] == plrc && is_avaiable_place(table[7]))
            return is_avaiable_place(table[1]-'0');
        else
        if(table[1] == plrc && is_avaiable_place(table[4]) && table[7] == plrc)
            return is_avaiable_place(table[4]-'0');
        else
        if(is_avaiable_place(table[1]) && table[4] == plrc && table[7] == plrc)
            return is_avaiable_place(table[7]-'0');



        if (table[2] == plrc && table[5] == plrc && is_avaiable_place(table[8]))
            return is_avaiable_place(table[8]-'0');
        else
        if(table[2] == plrc && is_avaiable_place(table[5]) && table[8] == plrc)
            return is_avaiable_place(table[5]-'0');
        else
        if(is_avaiable_place(table[2]) && table[5] == plrc && table[8] == plrc)
            return is_avaiable_place(table[2]-'0');
        return 0;
    }
    void nsX_StartGameLoop()
    {
        clr;
        playing = 1;
        int played;
        while(playing)
        {
            played = 0;
            //clr;
            print_table();
            putstr("\nPLAYER : [ ");
            putstr(___colors_list[get_player(its_me_player)->player_symbole_color]);
            putchar(its_me_player+48);
            clearcolor;
            putstr(" ] : [ ");
            putstr(___colors_list[get_player(its_me_player)->player_symbole_color]);
            putstr(get_player(its_me_player)->player_name);
            clearcolor;
            putstr(" ]");
            putstr("\n IS PLAYING...");
            putstr("\nENTER [1-9] TO SELECT:\tOR\tENTER [0] TO EXIT >\n>");
            if(get_player(its_me_player)->is_bot)
            {
                int rand;
                played = 1;
                char c = myenemy_very_close_to_win((its_me_player == 1) ? player2 : player1);
                if(c)
                {
                    input = c; 
                    putchar(input-48);
                }
                else
                {
                    
                    rand = random_number(10);
                    input = (rand == 0) ? 49 : rand+48;
                }
            }
            else
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
            else
            if(input >= '0' && input <= '9')
            {
                    if(table[input-48-1] >= '0' && table[input-48-1] <= '9')
                    {
                        played = 1;
                        table[input-49] = get_player(its_me_player)->player_symbole;
                    }
                    else
                    {
                        played = 0;
                        //the place already used :> 
                    }
            }
            clr;
            if(check_if_this_plr_winner(table,get_player(its_me_player)->player_symbole))
            {
                print_table();
                if(!stop_default_opw_func)
                    {
                        putstr("\nPLAYER : [ ");
                        putstr(___colors_list[get_player(its_me_player)->player_symbole_color]);
                        putchar(its_me_player+48);
                        clearcolor;
                        putstr(" ] : [ ");
                        putstr(___colors_list[get_player(its_me_player)->player_symbole_color]);
                        putstr(get_player(its_me_player)->player_name);
                        clearcolor;
                        putstr(" ] ");
                        putstr(___colors_list[Green]);
                        putstr("WINNER!!");
                        clearcolor;
                        putstr("\033[1;0m\n");
                    }
                if(OnPlayerWin)
                    OnPlayerWin(get_player(its_me_player));
                
                playing = 0;
                return;
            }
            if(!check_table_is_avaiable())
            {
                print_table();
                playing = 0;
                if(!stop_default_opw_func)
                    {
                        putstr(___colors_list[Red]);
                        putstr("\n:( PLAYERS ARE DRAW!!\n IT'S WAS BOOOOOOOOOOOOORING");
                        putstr("\033[1;0m\n");
                    }
                OnPlayersDraw();
                return;
            }
            if(played)
                _change_player();
        }
    }
    char *getTable()
    {
        return table;
    }
    void nsX_endGame()
    {
        free(table);
    }
};
nsx_GAME_ROUND *nsX_Init(player *player1,player *player2)
{
    int i = 0;
    player1->id = 1;
    player2->id = 2;
    nsx_GAME_ROUND *round = new nsx_GAME_ROUND(player1,player2);
    if(round == 0)
        return 0;
    return round;
}

