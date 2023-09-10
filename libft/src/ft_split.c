#include<stdlib.h>

char **ft_split(char const *s, char c)
{
    char **r;
    int i = 0;
    int j = 0;
    int wordcount = 0;
    int lenofword = 0;
    int wordindex = 0;
    while(s[i])
    {
        if(s[i] > 32)
        {
            while(s[i] > 32)
                i++;
            wordcount++;
        }
        i++;
    }
    r = malloc((wordcount + 1) * sizeof(char *));
    i = 0;
    while(*s)
    {
        if(*s != c)
        {
            //new the fucking word 
            lenofword = 0;
            while(s[lenofword] != ' ' && s[lenofword])
                lenofword++;
            j = 0;
            r[wordindex] = malloc((lenofword + 1) * sizeof(char));
            if (r[wordindex] == NULL)
            {
                return NULL;
            }
            while(j < lenofword)
            {
                r[wordindex][j] = s[j];
                j++;
            }
            r[wordindex][j] = '\0';
            s += lenofword;
            wordindex++;
        }
        s++;
    }
    r[wordcount] = '\0';
    return r;
}