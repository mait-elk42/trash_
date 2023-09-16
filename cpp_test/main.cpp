#include "User.cpp"
char *getstring(char *key,char *str)
    {
        int lenofvalue = 0;
        int i = 0;
        int j = 0;
        int ok = 0;
        while(*str)
            {
                ok = 0;
                j = 0;
                if(str[0] == key[0])
                {
                    while(key[j])
                    {
                        if(key[j] == str[j])
                            ok++;
                        j++;
                    }
                    str += j;
                    if(ok == j && *(str) == '~' && *(str+1) == '>')
                    {
                        str += 2;
                        while(*str != ',' &&  *str)
                        {
                            cout << *str;
                            lenofvalue++;
                            str++;
                        }
                        break;
                    }
                }
                str++;
            }
        cout <<endl << lenofvalue ;
    }
int main()
{
    User *user = new User((char *)"mohamed",18,male,(char *)"passwd",(char *)"myemail@gmail.com");

    char *name = (char *) user->get_name((char *)"passwd");
    char *infotext =(char *) user->get_user_info((char *)"passwd");
    cout << infotext << endl;
    getstring("e",infotext);
    return 0;
}