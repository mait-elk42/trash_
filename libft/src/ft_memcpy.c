void *ft_memcpy(void *dest, const void *src, int n)
{
    char *de = dest;
    int i = 0;
    while(i < n)
    {
        de[i] = ((char *)src)[i];
        i++;
    }
    return de;
}