#include<stdio.h>
#include "include/lists.h"
#define c (char*)
int main()
{
    nsX_LinkedList* list = new nsX_LinkedList();
    list->nsX_AddNewItem(c"name",c"New Stranger");
    list->nsX_AddNewItem(c"username",c"newstrangerX");
    //list->nsX_AddNewItem(c"age",c"18");
    list->nsX_AddNewItem(c"keys2",c"value3");

    list->PutValueInKey(c"age",c"999");
    list->Remove(2);
    printf("%s",list->nsX_GetValueInIndex(0));
}