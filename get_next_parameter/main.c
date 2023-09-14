#include<stdio.h>
#include<stdarg.h>
#include "mystdarg.h"


void prtargs(char *format ,...)
{
    my_startarg(&format);
    while(*format)
    {
        if(*format == '%')
        {
            format++;
            if(*format == 's')
            {
                printf("%s",get_next_parameter(charptr));
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
    prtargs("hello {%s %s %s %s}","ahelloww","bhelloww22","chelloww33","dhelloww5555");
    //prtnextpar("asdab",111,8222,9333);
}