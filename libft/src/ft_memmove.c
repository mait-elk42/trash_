void *ft_memmove(void *dest, const void *src, int n)
{
    int i = 0;
    while(((char *)src)[i] && i < n)
    {
        ((char *) dest)[i] = ((char *)src)[i];
        i++;
    }
    ((char *) dest)[i] = '\0';
    return dest;
}