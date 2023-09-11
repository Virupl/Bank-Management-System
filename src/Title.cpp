#include <iostream>

using namespace std;

// include file
#include "./../include/Title.hh"

void Title()
{
    cout << "\n\n\n\n";
    cout << "\t\t********************************************************************************" << endl;
    cout << "\t\t*                                                                              *" << endl;
    cout << "\t\t*                                                                              *" << endl;
    cout << "\t\t*=========================== BANK MANAGEMENT SYSTEM ===========================*" << endl;
    cout << "\t\t*                                                                              *" << endl;
    cout << "\t\t*                                                                              *" << endl;
    cout << "\t\t********************************************************************************" << endl;
    cout << "\n\n";

    cout << "\n\t\t\t\tPress any key for continue...\t";
    getchar();
}

/*------------------------------------------------------------------------------------*/

void headerTitle()
{
    string Loc_date = get_date();
    string Loc_time = get_time();

    cout << "\n\n\t\t\t\tBank Of Baroda";
    cout << "\n\nDate or Time : " << Loc_date << " or " << Loc_time;
}

/*------------------------------------------------------------------------------------*/

string get_date() // function to converts date to string
{
    time_t now;
    char the_date[15];

    the_date[0] = '\0';

    now = time(NULL);

    if (now != -1)
    {
        strftime(the_date, 15, "%d.%m.%y", gmtime(&now));
    }

    return string(the_date);
}

/*------------------------------------------------------------------------------------*/

string get_time()
{
    time_t rawtime;

    struct tm *timeinfo;

    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, "%I:%M %p", timeinfo);
    // puts(buffer);

    return string(buffer);
}