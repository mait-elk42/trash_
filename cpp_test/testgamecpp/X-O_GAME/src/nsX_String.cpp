#include<unistd.h>
#include<stdlib.h>
#include <time.h>

static int oldrandom = 0;

char ___colors_list[10][8]{
    "\033[1;30m",
    "\033[1;31m",
    "\033[1;32m",
    "\033[1;33m",
    "\033[1;34m",
    "\033[1;35m",
    "\033[1;36m",
    "\033[1;90m",
    "\033[1;97m"
};
enum colors_list {
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    Gray,
    White
};
int str_lenght(char *s)
{
    int i = 0;
    while(*s++)
        i++;
    return i;
}
int putchar(char c)
{
    write(1,&c,1);
    return 0;
}
int strcompare(char *s1,char *s2)
{
    while(*s1 || *s2)
        if(*s1 != *s2)
            return 0 + ((s1++ == s2++) *0);
    return 1;
}
void putstr(const char *s)
{
    while(*s)
        putchar(*s++);
}
void putnbr(long nb)
{
    int n = 1;
    char res[100];
    int i = 99;
    if(nb == 0)
    {
        putchar('0');
        return;
    }
    res[i+1] = '\0';
    if(nb < 0)
        n = (nb *= -1) * 0;
    while(i)
        res[i--] = '-';
    i = 99;
    while(nb)
    {
        res[i--] = (nb % 10) + 48;
        nb /= 10;
    }
    putstr(&res[i+n]);
}
void getinput(int *input)
    {
        char userinput[100];
        read(0,userinput,100);
        *input = userinput[0];
    }
int random_number(int max)
    {
        if(oldrandom == 0)
                srand(time(0));
        if(oldrandom == rand())
            random_number(max);
        return rand() % max + ((oldrandom = rand()) * 0);
    }