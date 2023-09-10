char *ft_strrchr(const char *s, int c)
{
    char *r;
    while(*s)
    {
        if(*s == c)
            r =(char *) s;
        s++;
    }
    return (char *)r;
}