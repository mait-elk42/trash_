#include<stdio.h>
#include<stdarg.h>
#include "mystdarg.h"


void prtargs(char *format ,...)
{
    my_startarg((void **)&format);
    while(*format)
    {
        if(*format == '%')
        {
            format++;
            if(*format == 's')
            {
                printf("%s",(char *)get_next_parameter(charptr));
            }else
            if(*format == 'd')
            {
                printf("%d",get_next_parameter(integer));
            }
        }
        else
            printf("%c", *format);
        format++;
    }
}

// void prt(char *format ,...)
// {
//     va_list list;
//     va_start(list,format);
//     while(*format)
//     {
//         if(*format == '%')
//         {
//             format++;
//             if(*format == 's')
//             {
//                 printf("%s",va_arg(list,char *));
//             }
//         }
//         else
//             printf("%c", *format);
//         format++;
//     }
// }
int main()
{
    prtargs("hello {%s %s %s %s %d}","ahelloww","bhelloww22","chelloww33","dhelloww5555",2313);
    //prtnextpar("asdab",111,8222,9333);
}