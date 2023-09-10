void ft_bzero(void *s, int n)
{
    char *str = s;
    int i = 0;
    while(str[i] && n != 0)
    {
        str[i++] = '\0';
        n--;
    }
}