void *ft_memchr(const void *s, int c, int n)
{
    while(*(char *)s != c)
        s++;
    return (void *)s;
}