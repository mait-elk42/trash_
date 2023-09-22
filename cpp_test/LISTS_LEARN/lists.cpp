#include "lists.h"

typedef struct _item{
    char *key;
    char *value;
    struct _item *next;
} item;

int compare_strings(char *s1,char *s2)
{
    while(*s1 || *s2)
        if(*(s1++) != *(s2++))
            return 0;
    return 1;
}
class LinkedList{
public:
    item *first;
    item *current;
public:
    int _AddNewItem(item* _item)
    {
        if(!_item->key || !_item->value)
            return 0;
        if(!first)
        {
            first = _item;
            current = first;
            return 1;
        }
        current->next = _item;
        current = current->next;
        return 1;
    }
    int AddNewItem(char *key, char *value)
    {
        if(!key || !value)
            return 0;
        return _AddNewItem(new item{key,value,0});
    }
    char* GetItemValue(char *key)
    {
        int found = 0;
        if(compare_strings(first->key,key))
        {
            return first->value;
        }
        item *currite = first->next;
        while(currite)
        {
             //search
            if(compare_strings(currite->key,key))
            {
                return currite->value;
            }
            currite = currite->next;
        }
        return 0;
    }
};