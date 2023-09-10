#include<stdlib.h>
void *calloc(size_t nmemb, size_t size)
{
    int i = 0;
    void * r = malloc(size * nmemb);
    while(((char *)r)[i])
        ((char *)r)[i] = '\0';
    if(r)
        return r;
    else
        return NULL;

}
