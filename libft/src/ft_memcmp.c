int ft_memcmp(const void *s1, const void *s2, int n)
{
    while(0 < n--)
        {
            if(*(char *)s1 != *(char *)s2)
                return *(char *)s1 - *(char *)s2;
            s1++;
            s2++;
        }
    return 0;
}