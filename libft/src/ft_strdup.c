#include<stdlib.h>

char * ft_strdup(const char *str)
{
    int i = 0;
    while(str[i])
        i++;
    char *r = malloc(i);
    i = 0;
    while(str[i])
        r[i] = str[i++];
    return r;
}