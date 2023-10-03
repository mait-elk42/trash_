#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#define BUFFER_SIZE 5

int len(char *s)
{
    int i = 0;
    while(*s++)
        i++;
    return i;
}
int pchar(char c)
{   
    if(c == '\n')
        pchar('$');
    write(1,&c,1);
    return 0;
}
int pstr(char *str)
{
    while(*str)
        pchar(*str++);
    return 0;
}
int freebuff(char **s)
{
    int i = 0;
    int r = 0;
    char *str = *s;
    while(str[i])
        str[i++] = '\0';
    return 0;
}
int main(int ac,char *av[])
{
    int fd = open(av[1],0);
    char c;
    int i = 0;
    int _$ = 0; 
    while(av[i])
    {
        if(av[i][0] == '-')
            if(av[i][1] == 'e')
                _$ = 1;
        i++;
    }

    char *buffer = (char*)malloc(BUFFER_SIZE);
    read(fd,&c,1);
    while(c)
    {
        i = 0;
        while(i < BUFFER_SIZE && c)
        {
            if(c != '\r')
                buffer[i++] = c;
            c = 0;
            read(fd,&c,1);
        }
        pstr(buffer);
        freebuff(&buffer);
    }
    close(fd);
}