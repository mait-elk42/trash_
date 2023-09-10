#include "ft_putchar_fd.c"

void ft_putstr_fd(char *s, int fd)
{
    while(*s)
        ft_putchar_fd(*s++,fd);
}