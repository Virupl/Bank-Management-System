#ifndef ADMIN
#define ADMIN

#include <string>

using namespace std;

class admin
{
private:
    string fName, lName, Mobile_No, Address, userId, Password;
    int Age;
    char Gender;

public:
    void input();
    void login();
    void showData();
    void adminAdd();
};

#endif