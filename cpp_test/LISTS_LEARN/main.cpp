#include "lists.h"
#include<stdio.h>

int main()
{
    nsX_LinkedList* list = new nsX_LinkedList();
    list->nsX_AddNewItem("kkeeyy","vvaalueeSDAS>DASDP)(ASD())");
    list->nsX_AddNewItem("key1","value1");
    list->nsX_AddNewItem("keys1","value2");
    list->nsX_AddNewItem("keys2","value3");
    list->nsX_AddNewItem("key4","value4");
    list->nsX_AddNewItem("key5","value5");
    list->nsX_AddNewItem("key6","value6");

    list->PutValueInKey("keys1","valyoo",2);
    // item *i2;
    // i2->key = "key2";
    // i2->value = "value2";

    // list->AddNewItem(i2);
    //printf("%s",list->GetValueInIndex(6));
    printf("%s",list->nsX_GetValueKey("keys1"));
}