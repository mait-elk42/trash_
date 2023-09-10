#include<stdlib.h>

void *ft_memset(void *s, int c, int n)
{

    char *str = s;
    int i = 0;
    while(str[i] && i < n)
        str[i++] = c;
    return str;
}