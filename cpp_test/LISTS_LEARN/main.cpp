#include "lists.h"
#include<stdio.h>

int main()
{
    LinkedList* list = new LinkedList();
    list->AddNewItem("key1","value1");
    list->AddNewItem("key2","value2");
    list->AddNewItem("key3","value3");
    list->AddNewItem("key4","value4");
    list->AddNewItem("key5","value5");
    list->AddNewItem("key6","value6");
    // item *i2;
    // i2->key = "key2";
    // i2->value = "value2";

    // list->AddNewItem(i2);
    printf("%s",list->GetItemValue("ke4y"));
}