void *ft_memccpy(void *dest, const void *src, int c, int n)
{

    char *de = dest;
    int i = 0;
    while(i < n && ((char*)src)[i] != c)
    {
        de[i] = ((char *)src)[i];
        i++;
    }
    return de;
}