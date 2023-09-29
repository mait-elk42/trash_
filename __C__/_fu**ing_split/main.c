#include<stdio.h>
#include<stdlib.h>

int wl(char *s)
{
    int r = 0;
    while(*s > 32)
    {
        r++;
        s++;
    }
    return r;
}
char *nextword(char *s)
{
    while(*s <= 32)
        s++;
    return (char *)s;
}
int wc(char *s)
{
    int r = 0;
    if(*s && *s > 32)
        {
            r++;
            s++;
        }
    while(*s)
    {
        if(*s)
            if(*(s-1) <= 32 && *s > 32)
                r++;
        s++;
    }
    return r;
}

char **mysplit(char *str)
{
    int i = 0;
    int j = 0;
    int wordscount = wc(str);
    char **result = malloc(8 * (wordscount + 1));
    str = nextword(str);
    while(wordscount > i)
    {
        int twl = wl(str);
        result[i] = malloc(twl);
        j = 0;
        while(*str > 32)
        {
            result[i][j++] = *str;
            str++;
        }
        str = nextword(str);
        i++;
    }
    result[i] = 0;
    return result;
}

int main()
{
    char *str =  " asd asd asa WORLD HELL ALALSDK KASK K";
    char **splitted = mysplit(str);
    while(*splitted)
        printf("%s\n",*splitted++);
    return 0;
}