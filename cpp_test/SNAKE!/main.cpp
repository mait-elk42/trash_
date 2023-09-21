#include "nsX_GAME.h"

void OnStart()
{
    write(1,"S",1);
}

void OnUpdate(int deltat)
{
    print(deltat);
    print("\n");
}



//
//int main()
//{
//
    // //THE PROBLEM IS THE CHECKER IS VERY VERY SLOOW
    // KEY *w = new KEY();
    // KEY *a = new KEY();
    // KEY *s = new KEY();
    // KEY *d = new KEY();
    // w->nextkey = a;
    // w->keycode = 'w';
    // a->nextkey = s;
    // a->keycode = 'a';
    // s->nextkey = d;
    // s->keycode = 's'; 
    // d->nextkey = 0;
    // d->keycode = 'd';
    // w->event = &OnClickWKey;
    // a->event = &OnClickAKey;
    // s->event = &OnClickSKey;
    // d->event = &OnClickDKey;
    // InputUser *iu = new InputUser();
    // iu->REG_KEY_ONCLICK(w);
    // if(w->clicked)
    // {
    //     write(1,":",1);
    // }
    // //iu->StartLoop();
//}