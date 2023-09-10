int ft_atoi(const char *s)
{
    int sign = 1;
    long r = 0;
    if(*s == '-' || *s == '+')
    {
        if(*s == '-')
            sign = -1;
        s++;
    }
    while(*s >= '0' && *s <= '9')
            r = (r *  10) - '0' + *s++;
    return r * sign;
}