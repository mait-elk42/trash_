#include "User.cpp"
char *getstring(char *key,char *str)
    {
        char *res;
        int lenofvalue = 0;
        int i = 0;
        int j = 0;
        int ok = 0;
        while(*str)
            {
                ok = 0;
                j = 0;
                if(str[0] == key[0] && !*(str-1) || *(str-1) == ',')
                {
                    while(key[j])
                    {
                        if(key[j] == str[j])
                            ok++;
                        j++;
                    }
                    str += j;
                    i = 0;
                    if(ok == j && *(str) == '~' && *(str+1) == '>')
                    {
                        str += 2;
                        while(str[i] != ',' &&  str[i])
                        {
                            lenofvalue++;
                            i++;
                        }
                        break;
                    }
                }
                str++;
            }
        i = 0;
        if(lenofvalue > 0)
        {
            res = (char*)malloc(lenofvalue + 1);
            if(!res)
                return 0;
            while(i < lenofvalue)
            {
                res[i] = str[i];
                i++;
            }
            res[i] = '\0';
        }
    return res;
    }
int main()
{
    User *user = new User((char *)"mohamed",18,male,(char *)"passwd",(char *)"myemail@gmail.com");

    char *name = (char *) user->get_name((char *)"passwd");
    char *infotext =(char *) user->get_user_info((char *)"passwd");
    cout << infotext << endl;
    char *emailfromtext = getstring("passwd",infotext);
    cout << "?" << emailfromtext << "?";
    return 0;
}