#include<stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    int i = 0;
    while(s[i])
        i++;
    char *r = malloc(i);
    if(!r)  return 0;
    i = 0;
    while(s[i] && i < len)
        r[i] = s[i++];
    return r;
}
