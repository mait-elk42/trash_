#include<stdlib.h>

int len(const char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return i;
}
char *ft_strjoin(char const *s1, char const *s2)
{
    int i = 0;
    i += len(s1);
    i += len(s2);
    char *r = malloc(i);
    if(!r) return 0;
    i = 0;
    while(*s1)
        r[i++] = *s1++;

    while(*s2)
        r[i++] = *s2++;

    return r;
}
