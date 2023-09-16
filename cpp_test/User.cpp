#include<iostream>
#include<stdlib.h>

using namespace std;
typedef enum _gender{
    male,
    female
} gender_type ;

int len(char *s)
{
    int i = 0;
    while(*s++)
        i++;
    return i;
}
class minicrypt {
private:
    char *bc;
public:
    minicrypt(char *basecrypting)
    {
        bc = basecrypting;
    }
    char *decrypt(char *str)
    {
        int i = 0;
        char *s = (char *)malloc(len(str) + 1);
        while(*str)
            s[i++] = (*str++) - (len(bc) * bc[0]);
        s[i] = '\0';
        return s;
    }
    char *encrypt(char *str)
    {
        int i = 0;
        char *s = (char *)malloc(len(str) + 1);
        while(*str)
            s[i++] = (*str++) + (len(bc) * bc[0]);
        s[i] = '\0';
        return s;
    }
    char *decrypt_passwd(char *str,char *passwd)
    {
        int i = 0;
        char *s = (char *)malloc(len(str) + 1);
        while(*str)
            s[i++] = (*str++) - (len(passwd) * bc[0]);
        s[i] = '\0';
        return s;
    }
    char *encrypt_passwd(char *str,char *passwd)
    {
        int i = 0;
        char *s = (char *)malloc(len(str) + 1);
        while(*str)
            s[i++] = (*str++) + (len(passwd) * bc[0]);
        s[i] = '\0';
        return s;
    }
};
class InfoTextGetter{
    char *getstring(char *key,char *str)
    {
        int lenofvalue = 0;
        int i = 0;
        int j = 0;
        int ok = 0;
        while(str[i])
            {
                ok = 0;
                j = 0;
                if(str[i] == key[0])
                {
                    while(key[j])
                    {
                        if(key[j] == str[i+j])
                            ok++;
                        j++;
                    }
                    if(ok == j)
                        while(str[i+j+2] != ',' &&  str[i+j+2])
                        {
                            lenofvalue++;
                        }
                    break;
                }
                i++;
            }
        cout << lenofvalue ;
    }
};
class User {

private:
    minicrypt *minicp;
    char *name;
    int age = 18;
    gender_type gender;
    char *passwd;
    char *email;
public:
    User(char *name,int age,gender_type gender,char *passwd,char *email)
    {
        minicp = new minicrypt(passwd);
        this->name  = minicp->encrypt(name);
        this->age = age;
        this->gender = gender;
        this->passwd = minicp->encrypt(passwd);
        this->email = minicp->encrypt(email);
    }
    char *get_name(char *passwd)
    {
        return minicp->decrypt_passwd(this->name,passwd);
    }
    char *get_email(char *passwd)
    {
        return minicp->decrypt_passwd(this->email,passwd);
    }
    char *get_passwd(char *passwd)
    {
        return minicp->decrypt_passwd(this->passwd,passwd);
    }
    char *get_user_info(char *passwd)
    {
        char *str;

        char *_name = (char *)"name~>";
        char *_email = (char *)"email~>";
        char *_passwd = (char *)"passwd~>";

        int i = 0;
        char *info;
        int len_t = 0;
        len_t += len(minicp->decrypt_passwd(this->name,passwd));
        len_t += len(minicp->decrypt_passwd(this->email,passwd));
        len_t += len(minicp->decrypt_passwd(this->passwd,passwd));
        len_t += (len(_name)+len(_email)+len(_passwd));

        //first 1 for \0 and second 2 for , in the end
        info =(char *) malloc(len_t + 1 + 2);


    
        len_t = 0;
        str = _name;
        while(str[len_t])
            info[i++] = str[len_t++];


        len_t = 0;
        str = minicp->decrypt_passwd(this->name,passwd);
        while(str[len_t])
            info[i++] = str[len_t++];
        
        info[i++] = ',';

        len_t = 0;
        str = _email;
        while(str[len_t])
            info[i++] = str[len_t++];

        
        len_t = 0;
        str = minicp->decrypt_passwd(this->email,passwd);
        while(str[len_t])
            info[i++] = str[len_t++];
        
        info[i++] = ',';
        
        len_t = 0;
        str = _passwd;
        while(str[len_t])
            info[i++] = str[len_t++];
        
        len_t = 0;
        str = minicp->decrypt_passwd(this->passwd,passwd);
        while(str[len_t])
            info[i++] = str[len_t++];
        
        info[i] = '\0';
        return info;
    }
    gender_type get_gender()
    {
        return this->gender;
    }
};