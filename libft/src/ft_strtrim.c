#include<stdlib.h>

int isset(char c, const char *s)
{
    while(*s)
        if(c == *s++)
            return 1;
    return 0;
}
char *ft_strtrim(char const *s1, char const *set)
{
    int i = 0;
    while(s1[i])
        i++;
    char *r = malloc(i);
    i = 0;
    while(*s1)
        {
            if(!isset(*s1,set))
                r[i++] = *s1;
            s1++;
        }
    return r;
}
