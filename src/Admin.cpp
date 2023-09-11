#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sstream>

using namespace std;

// include file
#include "./../include/Admin.hh"
#include "./../include/rlpage.hh"
#include "./../include/Title.hh"
#include "./../include/customer.hh"

void admin::input()
{
    ofstream fout, fip;
    fout.open("./data_files/admin.txt", ios::out);
    fip.open("./data_files/adminIP.txt", ios::out);
    if (fout.fail() || fip.fail())
    {
        cout << "\n\n\t\tFiles opened failed!" << endl;
        usleep(1000000);
        rlPage();
    }
    else if (fout.is_open())
    {

        cout << "\n\n\t\t\tADMIN DETAILS" << endl;
        cout << "\n\n\t\tEnter First Name :- ";
        cin >> fName;
        cout << "\n\t\tEnter Last Name :- ";
        cin >> lName;
        cout << "\n\t\tEnter Age :- ";
        cin >> Age;
        cout << "\n\t\tEnter Gender :- ";
        cin >> Gender;
        while (Gender != 'M' && Gender != 'F')
        {
            cout << "\t\tM or F? :- ";
            cin >> Gender;
        }
    a:
        cout << "\n\t\tEnter Mobile No :- ";
        cin >> Mobile_No;
        int SIZE = Mobile_No.length();
        if (SIZE > 12 || SIZE < 10)
        {
            cout << "\n\t Only 10 Digit Mobile No. Valid. Please Enter Right Number" << endl;
            usleep(2000000);
            goto a;
        }
        cout << "\n\t\tEnter Address :- ";
        cin >> Address;
        cout << "\n\t\tEnter User Id :- ";
        cin >> userId;
        cout << "\n\t\tEnter Password :- ";
        cin >> Password;

        fout << "\n\t\t\t\tADMIN DETAILS"
             << "\n\n\t\tFull Name :- " << fName << " " << lName
             << "\n\t\tAge :- " << Age
             << "\n\t\tGender :- " << Gender
             << "\n\t\tMobile No :- " << Mobile_No
             << "\n\t\tAddress :- " << Address;

        fip << userId << endl
            << Password;
    }
    fout.close();
    fip.close();
}

void admin::login()
{
r:

    system("clear");
    headerTitle();

    ifstream fin;
    fin.open("./data_files/adminIP.txt", ios::in);

    if (fin.fail())
    {
        cout << "\n\n\t\tFiles opened failed!" << endl;
        usleep(1000000);
        rlPage();
    }
    else if (fin.is_open())
    {
        string line, temp_id, temp_pass, ori_id, ori_pass;

        cout << "\n\n\t\t\tADMIN DETAILS" << endl;
        cout << "\n\n\t\tEnter UserId :- ";
        cin >> temp_id;
        cout << "\n\t\tEnter Password :- ";
        cin >> temp_pass;

        fin >> ori_id >> ori_pass;

        if (ori_id == temp_id && ori_pass == temp_pass)
        {
            cout << "\n\n\t\t\tLogin Successfully \n\n";
            usleep(2000000);
            adminAdd();
        }
        else
        {
            cout << "\n\n\tWrong Id and Password. Please Enter Valid Entry.\n";
            usleep(2000000);
            goto r;
        }
    }

    fin.close();
}

void admin::showData()
{
    ifstream fin;
    fin.open("./data_files/admin.txt", ios::in);
    if (fin.fail())
    {
        cout << "\n\n\t\tFiles opened failed!" << endl;
        usleep(1000000);
        admin ad;
        ad.adminAdd();
    }
    else if (fin.is_open())
    {
        string line;

        cout << "\n\n\t\t\t\tADMIN DATA\n\n\n";
        while (getline(fin, line))
        {
            cout << line << endl;
        }
        cout << "\n";
        getchar();

        cout << "\n\t\tPress any key for back...\t";
        getchar();
        usleep(1000000);
    }
}

void admin::adminAdd()
{
r:
    system("clear");
    headerTitle();

    cout << "\n\n\n\t\tPlease, Choose from the following Option:\n";
    cout << "\n\t=========================================================";
    cout << "\n\t||               [1] Custemer Data                     ||";
    cout << "\n\t||               [2] All Custemer Data                 ||";
    cout << "\n\t||               [3] Admin Data                        ||";
    cout << "\n\t||               [4] Exit                              ||";
    cout << "\n\t=========================================================";

    cout << "\n\n\n\t\t\tEnter a number :- ";
    int i;
    cin >> i;

    if (i == 1)
    {
    a:
        system("clear");
        headerTitle();

        customer cs;
        cs.perData();

        cout << "\n\n\t\tDo you want add seen customer (Y/N) :- ";
        char ch;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            usleep(1000000);
            goto a;
        }
        else if (ch == 'N' || ch == 'n')
        {
            cout << "\n\t\t\t\tThanks You :) \n";
            usleep(2000000);
            adminAdd();
        }
    }
    else if (i == 2)
    {
        system("clear");
        headerTitle();

        customer cs;
        cs.allData();

        admin ad;
        ad.adminAdd();
    }
    else if (i == 3)
    {
        system("clear");
        headerTitle();

        admin ad;
        ad.showData();

        ad.adminAdd();
    }
    else if (i == 4)
    {
        rlPage();
    }
    else
    {
        cout << "\n\n\t\tPlease Choose Right Option.\n";
        usleep(2000000);
        goto r;
    }
}
