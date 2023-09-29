#include<stdio.h>
#include<stdlib.h>

int wl(char *s,char c)
{
    int r = 0;
    while(*s && *s != c)
    {
        r++;
        s++;
    }
    return r;
}
char *nextword(char *s,char c)
{
    while(*s == c)
        s++;
    return (char *)s;
}
int wc(char *s,char c)
{
    int r = 0;
    if(*s && *s != c)
        {
            r++;
            s++;
        }
    while(*s)
    {
        if(*s)
            if(*(s-1) == c && *s > 32)
                r++;
        s++;
    }
    return r;
}

char **mysplit(char *str,char c)
{
    int i = 0;
    int j = 0;
    int wordscount = wc(str,c);
    char **result = malloc(8 * (wordscount + 1));
    str = nextword(str,c);
    while(wordscount > i)
    {
        int twl = wl(str,c);
        result[i] = malloc(twl + 1);
        j = 0;
        while(*str && *str != c)
        {
            result[i][j++] = *str;
            str++;
        }
        result[i][j] = 0;
        str = nextword(str,c);
        i++;
    }
    result[i] = 0;
    return result;
}

int main()
{
    char *str =  "   HELLO WORLD,FUFUFUF KMAM,AKS,,,,";
    char **splitted = mysplit(str,',');
    char **splitted2 = mysplit(str,',');
    char **splitted3 = mysplit(str,',');
    while(*splitted3)
        printf("%s\n",*splitted3++);
    //printf("%d\n",wl(str,','));
    return 0;
}