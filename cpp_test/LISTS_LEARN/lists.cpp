
typedef struct _item{
    char *key;
    char *value;
    struct _item *next;
} item;

int compare_strings(char *s1,char *s2)
{
    while(*s1 || *s2)
        if(*s1 != *s2)
            if(*(s1++) == '*' || *(s2++) == '*')
                return 1;
            else
                return 0;
        else
            *(s1++)+*(s2++);
    return 1;
}
class nsX_LinkedList{
private:
    item *first;
    item *current;
    int ItemsCount = 0;
public:
    int _AddNewItem(item* _item)
    {
        if(!_item->key || !_item->value)
            return 0;
        if(!first)
        {
            first = _item;
            current = first;
            ItemsCount++;
            return 1;
        }
        current->next = _item;
        current = current->next;
        ItemsCount++;
        return 1;
    }
    int nsX_AddNewItem(char *key, char *value)
    {
        if(!key || !value)
            return 0;
        return _AddNewItem(new item{key,value,0});
    }
    int nsX_ItemsCount()
    {
        return ItemsCount;
    }
    char* nsX_GetValueInIndex(int index)
    {
        int i = 0;
        item *currite = first;
        if(index > ItemsCount || index < 0)
            return 0;
        while(i++ < index)
            currite = currite->next;
        if(currite)
            return currite->value;
        return 0;
    }
    char* nsX_GetValueKey(char *key)
    {
        int found = 0;
        item *currite = first;
        while(currite)
        {
            if(compare_strings(currite->key,key))
                return currite->value;
            currite = currite->next;
        }
        return 0;
    }
    int PutValueInKey(char *key,char *value)
    {
        int i = 0;
        item *currite = first;
        while(i++ < ItemsCount)
            currite = currite->next;
        if(currite)
            currite-> value = value;
        return 1;
    }
};