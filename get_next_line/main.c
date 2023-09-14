#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

struct t_list{
    char *s;
    struct t_list *next;    
} l_list;
int len(char *s,int ___bool)
{
    int i = 0;
    while(*s && ___bool)
        i++;
    return i;
}
int get_next_line(int fd, char **line)
{
    char buff[BUFFER_SIZE + 1];
    int i = 0;
    int j = 0;
    int need_to_malloc = 0;
    while(read(fd,buff,BUFFER_SIZE))
        {
            i = 0;
            while(buff[i] && buff[i++] != '\n')
                need_to_malloc++;
        }

    return 0;
}
int     main(void)
{
    int     fd;
    int     ret;
    char    *line;
 
    printf("%d\n",BUFFER_SIZE);
    if ((fd = open("main.c", 2)) < 3 && fd != 0)
        return (-1);
    printf("%d\n", fd);
    ret = get_next_line(fd, &line);
    printf("%d - %s\n", ret, line);
    ret = get_next_line(fd, &line);
    printf("%d - %s\n", ret, line);
    ret = get_next_line(fd, &line);
    printf("%d - %s\n", ret, line);
    ret = get_next_line(fd, &line);
    printf("%d - %s\n", ret, line);
    return (0);
}