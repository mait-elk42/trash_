#ifndef _MYSTDARG_H
#define _MYSTDARG_H
void ** argsoffset;
typedef enum{
    integer,
    charptr
} _vartype;
void my_startarg(void **adress_of_firstparam)
{
    argsoffset = adress_of_firstparam+2;
}
int getcountofpars()
{
    /////trash hhshshhshhshsh
    (char **)argsoffset;
    int c = 0;
    //printf("%s\n",argsoffset[c++]);
    //printf("%s\n",argsoffset[c++]);
    //printf("%s\n",argsoffset[c++]);
    //printf("%s\n",argsoffset[c++]);
    //printf("%s\n",argsoffset[c++]);
    //printf("%s\n",argsoffset[c++]);
    // while(*argsoffset)
    // {
    //     printf("%s\n",argsoffset[c]);
    //     argsoffset++;
    //     c++;
    // }
    argsoffset -= c;
    return c;
}
void* get_next_parameter(_vartype vartype)
{
    if(argsoffset)
        return *(argsoffset++);
    else
        return 0;
}
#endif