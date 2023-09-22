#include <conio.h>
#include<unistd.h>
#include<stdlib.h>


typedef struct _KEY{
    char keycode;
    int clicked;
    void (*event)();
    _KEY* nextkey;
} KEY;
int GetInputKey()
{
    return getch();
}
class InputUser{
private:
    int index = 0;
    KEY *keys;
public:
    int clicked = 0;
int REG_KEY_ONCLICK(KEY *fkey)
{
    keys = fkey;
}
void StartLoop()
{
    KEY *keystart;
    while(1)
        {
            keystart = keys;
            char c = getch();
            while(keystart)
            {
                if(c == keystart->keycode)
                {
                    if(keystart->event)
                        keystart->event();
                    keystart->clicked = 1;
                }
                else
                    keystart->clicked = 0;
                keystart = keystart->nextkey;  
            }
    }
}
};
