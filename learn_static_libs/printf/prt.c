#include <unistd.h>
#include<stdarg.h>
void prtch(char c)
{
    write(1,&c,1);
}
void prtstr(char *s)
{
    while(*s)
        prtch(*s++);
}
void prtnbr(int n)
{
    char n2 = n+48;
    if(n < 10)
        prtch(n2);
    else
        {
            prtnbr(n / 10);
            prtnbr(n % 10);
        }
}

int prt(char *format, ...)
{
    va_list args;
    va_start(args,format);
    if(!format)
        return 0;
    while(*format)
    {
        if(*format == '%')
        {
            format++;
            if(*format == 's')
            {
               prtstr(va_arg(args,char *));
            }else
            if(*format == 'c')
            {
                prtch(va_arg(args,int));
            }else
            if(*format == 'd')
            {
                prtnbr(va_arg(args,int));
            }else
            {
                prtch('?');
            }
        }
        else
        {
            write(1,format,1);
        }
        format++;
    }
    return 1;
}