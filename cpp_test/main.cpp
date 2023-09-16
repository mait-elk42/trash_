#include "User.cpp"

int main()
{
    User *user = new User(
        (char *)"mohamed",
        18,
        male,
        (char *)"mypasswd",
        (char *)"usa8dasyd7@gmail.com"
        );

    char *name = (char *) user->get_name((char *)"mypasswd");
    char *infotext =(char *) user->get_user_info((char *)"mypasswd");

    cout << infotext << endl;
    char *emailfromtext = InfoTextGetter::getstring((char *)"email",infotext);
    cout << "GENDER :" << (char)user->get_gender() << "\n";

    cout << "emailfromtext >\n" << emailfromtext << "\n";
    free(name);
    free(infotext);
    free(emailfromtext);
    return 0;
}