int ft_strlcat(char *dest, const char *src, int size)
{
    int i = 0;
    int i2 = 0;
    while(dest[i])
        i++;
    while(src[i2++] && i2 < size)
        dest[i++] = src[i2++];
    return i2;
}
