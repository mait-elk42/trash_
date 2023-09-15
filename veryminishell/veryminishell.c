#include<stdio.h>

void system(char *s);
int strcmp(char *s1,char *s2);
int main()
{
    while(1)
    {
        char input[10];
        printf("\nunknown@newstrangerX > ");
        gets(&input);
        if(strcmp(input,"exit") == 0)
            break;
        else
        if(strcmp(input,"ls") == 0)
            system("ls");
        else
        if(strcmp(input,"cd ..") == 0)
            system("cd ..");
        else
        if(strcmp(input,"pwd") == 0)
            system("pwd");
        else
            printf("UNKNOWN COMMAND : %s",input);

    }
    printf("\n");
}