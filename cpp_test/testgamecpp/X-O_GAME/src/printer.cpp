#include<iostream>
#include<unistd.h>
using namespace std;

void putchar(void *c)
{
    write(1,(char*)c,1);
}
void putstr(const char *s)
{
    while(*s)
        putchar(*s++);
}
int str_lenght(char *s)
{
    int i = 0;
    while(*s++)
        i++;
    return i;
}
void putnbr(long nb)//178
{
    int i[2] = {0,0};
    char res[100];
    if(nb <= 0)
        if(nb == 0)
            putchar('0');
        else
            putchar('-'+ ((nb*=-1)*0));
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

int main()
{
    putnbr(-1273472734283483);
}