#include "nsX_GAME.h"

void OnStart()
{
    print("STARTED\n");
}
void OnUpdate(int i)
{
    //RUN CODE EVERY SINGLE 
    print("\nWORKING...");
    if(i == 1000)
        ENDGAME();
}
void OnExit()
{
    print("\nEXIT");
}