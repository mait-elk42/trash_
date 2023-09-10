#include<stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *r;
    int i;
    int slen = 0;
    while(s[slen])
        slen++;
    r = malloc(slen+1);
    if(!r)
        return 0;
    i = 0;
    while(s[i])
    {
        r[i] = f(i,s[i]);
        i++;
    }
    r[i] = '\0';
    return r;
}