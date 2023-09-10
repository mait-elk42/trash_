char *ft_strnstr(const char *s1 , const char *s2, int n)
{
    int f = 0;
    int g = 0;
    int i = 0;
    while(*s1 && i < n)
    {
        g = 0;
        f = 0;
        while(s2[g])
            {
                if(s1[g] == s2[g])
                    f++;
                g++;
            }
        if(g == f)
            return (char *)s1;
        s1++;
    }
    return (char *)s1;
}
