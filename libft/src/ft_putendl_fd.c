#include "ft_putstr_fd.c"

void ft_putendl_fd(char *s, int fd)
{
    ft_putstr_fd(s,fd);
    ft_putstr_fd("\n",fd);
}