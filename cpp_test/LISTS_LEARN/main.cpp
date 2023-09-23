#include<stdio.h>
#include "lists.h"
#define c (char*)
int main()
{
    nsX_LinkedList* list = new nsX_LinkedList();
    list->nsX_AddNewItem(c"kkeeyy",c"vvaalueeSDAS>DASDP)(ASD())");
    list->nsX_AddNewItem(c"key1",c"value1");
    list->nsX_AddNewItem(c"keys1",c"value2");
    list->nsX_AddNewItem(c"keys2",c"value3");
    list->nsX_AddNewItem(c"key4",c"value4");
    list->nsX_AddNewItem(c"key5",c"value5");
    list->nsX_AddNewItem(c"key6",c"value6");

    list->PutValueInKey(c"keys1",c"valyoo");
    
    //list->PutValueInKey("keys1");
    // item *i2;
    // i2->key = "key2";
    // i2->value = "value2";
    list->RemoveValueKey(c"key5");
    // list->AddNewItem(i2);
    //printf("%s",list->GetValueInIndex(6));
    printf("%s",list->nsX_GetValueInIndex(5));
}