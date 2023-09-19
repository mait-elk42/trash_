#include<unistd.h>

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
namespace PRINTER{
int str_lenght(char *s)
{
    int i = 0;
    while(*s++)
        i++;
    return i;
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
void putnbr(long nb)
{
    int i[2] = {0,0};
    char res[100];
    if(nb <= 0)
        if(nb == 0)
            putchar('0');
        else
            {putchar('-'); nb*=-1;}
    while(nb > 0)
        if(nb > 9)
            res[i[0]++] = (nb % 10) + 48 + ((nb /= 10) == 0);
        else
            res[i[0]++] = nb + 48 + ((nb = 0) == 1);
    i[0] = 0;
    i[1] = str_lenght(res)-1;
    while((i[0] != i[1]) && (i[0] < i[1]))
    {
        res[i[0]] += res[i[1]];//r1 = r1(8) + r2(1) ==> 9
        res[i[1]] = res[i[0]] - res[i[1]];//r2 = r1(9) - r2(1) ==> 8
        res[i[0]] -= res[i[1]];//r1 = r1(9) - r2(8) ==> 1 -> then r1 => 1 and r2 => 8 MAGIC RIGHT ! XD
        i[0]++;
        i[1]--;
    }
    putstr(res);
}
// void putstr_color(const char *s,colors_list color)
// {
//     putstr("\033[");
//     putnbr(color);
//     putchar('m');
//     putstr(s);
//     putstr("\033[");
//     putchar('0');
//     putchar('m');
// }
// void putchar_color(const char c,colors_list color)
// {
//     putstr("\033[");
//     putnbr(color);
//     putchar('m');
//     putchar(c);
//     putstr("\033[");
//     putchar('0');
//     putchar('m');
// }
void getinput(int *input)
    {
        char userinput[100];
        read(0,userinput,100);
        *input = userinput[0];
    }
}