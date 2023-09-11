#include <iostream>
#include <unistd.h>

using namespace std;

// include file
#include "./../include/rlpage.hh"
#include "./../include/Title.hh"
#include "./../include/Admin.hh"
#include "./../include/customer.hh"

void rlPage()
{
a:
    system("clear");
    headerTitle();

    cout << "\n\n\n\t\tPlease, Choose from the following Option:\n";
    cout << "\n\t\t[1] Regitration";
    cout << "\n\t\t[2] Login";

    int i;
    cout << "\n\n\t\t\tEnter a number : ";
    cin >> i;

    if (i == 1)
    {
        system("clear");
        headerTitle();

        admin ad;
        ad.input();

        getchar();
        goto a;
    }
    else if (i == 2)
    {
    b:
        system("clear");
        headerTitle();

        cout << "\n\n\n\t\tPlease, Choose from the following Option:\n";
        cout << "\n\t\t[1] Admin Login";
        cout << "\n\t\t[2] Customer Login";
        cout << "\n\t\t[3] Go Back";

        int n;
        cout << "\n\n\t\t\tEnter a number : ";
        cin >> n;

        if (n == 1)
        {
            admin ad;
            ad.login();
        }
        else if (n == 2)
        {
            customer cs;
            cs.login();
        }
        else if (n == 3)
        {
            rlPage();
        }
        else
        {
            cout << "\n\t\tPlease, Choose Right Option...";
            usleep(2000000);
            goto b;
        }

        getchar();
    }
    else
    {
        getchar();
        cout << "\n\t\tPlease, Choose Right Option...";
        usleep(2000000);
        goto a;
    }
}
