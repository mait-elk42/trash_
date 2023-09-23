
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
class nsX_LinkedList {
private:
    item *first;
    item *current;
    int ItemsCount = 0;
public:
    nsX_LinkedList()
    {
        first = new item();
        current = first;
    } 
    int _AddNewItem(item* _item)
    {
        if(!_item->key || !_item->value)
            return 0;
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
    item* _GetItemInIndex(int index)
    {
        item *currite = first->next;
        if(index > ItemsCount || index < 0)
            return 0;
        while(index--)
            currite = currite->next;
        if(currite)
            return currite;
        return 0;
    }
    item* _GetItemInKey(char* key)
    {
        item *currite = first;
        while(currite = currite->next)
            if(compare_strings(currite->key, key))
                return currite;
        return 0;
    }
    char* nsX_GetValueInIndex(int index)
    {
        item *currite = _GetItemInIndex(index);
        if(currite)
            return currite->value;
        return 0;
    }
    char* nsX_GetValueKey(char *key)
    {
        item *currite = _GetItemInKey(key);
        if(currite)
            return currite->value;
        return 0;
    }
    int Remove(char *key)
    {
        item * item_wanttoremove = first;
        if(!item_wanttoremove)
            return 0;
        while(item_wanttoremove)
        {
            if(item_wanttoremove->next && compare_strings(item_wanttoremove->next->key,key))
            {
                //delete item_wanttoremove->next;
                item_wanttoremove->next = item_wanttoremove->next->next;
                ItemsCount--;
                return 1;
            }
            else
                item_wanttoremove = item_wanttoremove->next;
        }
        return 0;
    }
    int Remove(int index)
    {
        item * item_wanttoremove = first;
        if(!item_wanttoremove)
            return 0;
        while(index--)
        {
            item_wanttoremove = item_wanttoremove->next;
        }
        if(!item_wanttoremove)
            return 0;
        //delete item_wanttoremove->next;
        item_wanttoremove->next = item_wanttoremove->next->next;
        return 0;
    }
    int PutValueInKey(char *key,char *value)
    {
        item *currite = _GetItemInKey(key);
        if(!currite)
            return 0;
        currite-> value = value;
        return 1;
    }
    int PutValueInIndex(char *value,int index)
    {
        int i = 0;
        item *currite = _GetItemInIndex(index);
        if(!currite)
            return 0;
        currite-> value = value;
        return 1;
    }
};