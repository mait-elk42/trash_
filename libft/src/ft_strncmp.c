int ft_strncmp(const char *s1, const char *s2,int n)
{
    int i = 0;
    while(*s1 || *s2 && i < n)
        if(*s1 != *s2)
            return *s1 - *s2;
        else
            {s1++;s2++;i++;}
    return 0;
}
