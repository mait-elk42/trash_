int strlcpy(char *dest, const char *src, int n)
{
    int i = 0;
    int i2 = 0;
    while(dest[i])
        i++;
    while(src[i2] && i2 < n)
        dest[i++] = src[i2++];
    return i2;
}