#include "ft_putstr_fd.c"
#include "ft_itoa.c"

void ft_putnbr_fd(int n, int fd)
{
    char *s = ft_itoa(n);
    ft_putstr_fd(s,fd);
}