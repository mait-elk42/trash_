#include<stdlib.h>

char *ft_itoa(int n)
{
    char *r;
    int i = 0;
    int intlen = 0;
    int sign = 1;
    if(n < 0)
        sign = -1;
    while((n/=10)/10)//ex: n = 232
        intlen++;
    if(sign < 0)
    {
        r = malloc(intlen+1);
        r[i++] = '-';
    }
    else
        r = malloc(intlen);
    while(n % 10)
        r[i] = (n/=10) % 10;
    return r;
        
}
