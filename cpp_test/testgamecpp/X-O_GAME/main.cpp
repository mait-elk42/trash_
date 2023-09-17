#include<iostream>
#include<unistd.h>
using namespace std;

#define clr system("clear")
#define player1 'x'
#define player2 'o'
#define red "\e[1;31m"
#define blue "\e[1;34m"
#define p1color red
#define p2color blue
#define reset "\e[0m"
#define itoaa(i)(i + 48)
static int its_me_player = 1;
void getinput(int *input)
{
    cin >> *input;
}
void putchar(char c)
{
    write(1,&c,1);
}
void putstr(const char *s)
{
    while(*s)
        putchar(*s++);
}
void prttable(char table[9])
{
    int i = 0;
    while(table[i])
        {
            putstr("\e[0m");
            if(table[i] == player1)
                putstr(red);//red
            
            else
            if(table[i] == player2)
                putstr(blue);//blue
            
            putchar(table[i]);
            putchar(' ');
            if(i == 2 || i == 5 || i == 8)
                write(1,"\n",1);
            i++;
            putstr(reset);
        }
}
int checkifthisplrwinner(char *table,char plrc)
{
    if ((table[0] == plrc && table[4] == plrc && table[8] == plrc) || // Diagonal from top-left to bottom-right
        (table[2] == plrc && table[4] == plrc && table[6] == plrc) || // Diagonal from top-right to bottom-left
        (table[0] == plrc && table[1] == plrc && table[2] == plrc) || // Top row
        (table[3] == plrc && table[4] == plrc && table[5] == plrc) || // Middle row
        (table[6] == plrc && table[7] == plrc && table[8] == plrc) || // Bottom row
        (table[0] == plrc && table[3] == plrc && table[6] == plrc) || // Left column
        (table[1] == plrc && table[4] == plrc && table[7] == plrc) || // Middle column
        (table[2] == plrc && table[5] == plrc && table[8] == plrc))   // Right column
            return 1;
        return 0;
}
char checkiftherewinner(char *table)
{
    //check for x player
    if(checkifthisplrwinner(table,player1))
        return player1;
    else
    if(checkifthisplrwinner(table,player2))
        return player2;
    else
        return '-';
    
}
int main()
{
    int input;
    int playing = 1;
    char *table = new char[9];
    its_me_player = 0;
    while(its_me_player < 9)
        table[its_me_player++] = its_me_player+49;
    its_me_player = 1;
    while(playing)
    {
        clr;
        prttable(table);
        char winner = checkiftherewinner(table);
        if(winner != '-')
        {
            if(winner == player1)
                cout << p1color << "PLAYER 1 winner :>";
            else
            if(winner == player2)
                cout << p2color << "PLAYER 2 winner :>";
            cout << reset << endl <<"SEE YOU LATER ^_^";
            playing = 0;
            break;

        }
        putstr("it's time of player : ");
        putstr((its_me_player == 1) ? "1[X]\n >> " : "2[O]\n >> ");
        getinput(&input);
        if(input == 99)
        {
            playing = 0;
        }
        else
        {
            char place = table[input-1];
            if(place <= itoaa(9) && place >= itoaa(0))
            {
                if(its_me_player == 1)
                    {table[input-1] = player1; its_me_player = 2;}
                else if(its_me_player == 2)
                    {table[input-1] = player2; its_me_player = 1;}
            }
            else
            {
                //DOES NOT WORK AND I'M LAZY TO FIX THIS
                putstr("Already Selected!!\n");
            }
        }
        
    }
}