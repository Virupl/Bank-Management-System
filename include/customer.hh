#ifndef CUSTEMER
#define CUSTEMER

using namespace std;

#include <string>

class customer
{
private:
    long long Account_No = 100504300001;
    const string IFSC_Code = "BARB0RATLAM";

    string fName, lName, Mobile_No, Address, pass, cpass;
    int Age;
    char Gender;
    double Op_bal, Total_bal = 0, Credit_bal = 0, Deposit_bal = 0;

public:
    long long lastlineReadCSV();
    void input();
    void perData();
    void allData();
    void login();
    void cuLogin();
    void doCustomer(string acno);
    void creditBal(string acno);
    void debitBal(string acno);
};

#endif
