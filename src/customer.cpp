#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <sstream>

using namespace std;

//  include file
#include "./../include/Title.hh"
#include "./../include/customer.hh"
#include "./../include/Admin.hh"
#include "./../include/rlpage.hh"

long long customer::lastlineReadCSV()
{
    // Open the CSV file for reading
    ifstream infile("./data_files/customer.csv");

    // Create a vector to store the lines of the CSV file
    vector<string> lines;

    // Read each line of the CSV file and store it in the vector
    string line;
    while (getline(infile, line))
    {
        lines.push_back(line);
    }

    // Get the last line of the CSV file
    string lastLine = lines.back();
    // cout << lastLine << endl;

    // Use a string stream to split the line into words
    istringstream iss(lastLine);
    string firstWord;
    getline(iss, firstWord, ',');

    // Print the first word of the last line of the CSV file
    // cout << firstWord << endl;

    // long long num = stol(firstWord);
    long long num = atol(firstWord.c_str());
    // num++;
    // cout << num << endl;
    infile.close();
    return num;
}

void customer::input()
{
    fstream fcus;
    fcus.open("./data_files/customer.csv", ios::app | ios::in);

    if (fcus.fail())
    {
        cout << "\n\n\t\tFiles opened failed!" << endl;
        usleep(1000000);
        admin ad;
        ad.adminAdd();
    }
    else if (fcus.is_open())
    {
        cout << "\n\n\t\t\tCUSTOMER DETAILS" << endl;
        cout << "\n\n\t\tEnter First Name :- ";
        cin >> fName;
        cout << "\n\t\tEnter Last Name :- ";
        cin >> lName;
        cout << "\n\t\tEnter Age :- ";
        cin >> Age;
        cout << "\n\t\tEnter Gender (M for Male // F for Female) :- ";
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

    b:
        cout << "\n\t\tEnter Password :- ";
        cin >> pass;

        cout << "\n\t\tReenter Password :- ";
        cin >> cpass;
        if (pass != cpass)
        {
            cout << "\n\t\tPassword is not match\n";
            goto b;
        }

        cout << "\n\t\tEnter Account Opening Balance :- ";
        cin >> Op_bal;

        Total_bal = Op_bal;

        // Create a vector to store the data
        vector<string> data;

        // Read the first line from the CSV file
        string line;
        getline(fcus, line);

        // Use a stringstream to split the line into fields
        stringstream ss(line);
        string field;
        while (getline(ss, field, ','))
        {
            // Add each field to the data vector
            data.push_back(field);
        }

        // Print the data vector
        // for (auto field : data)
        // {
        //     cout << field << " ";
        // }
        // cout << endl;

        if (!data.empty())
        {

            long long num = lastlineReadCSV();
            // cout << num << endl;
            if (num == 0)
            {
                Account_No = 100504300001;
            }
            else
            {
                num = num + 1;
                Account_No = num;
                // cout << Account_No << endl;
            }

            string ls = data[0];

            // cout << ls << endl;

            if ("AccountNo" != ls)
            {
                fcus.seekp(0, ios::beg);
                fcus << "AccountNo, IFSC Code, First Name, Last Name, Age, Gender, Mobile No, Address, Password, Total Balance, Credited Balance, Debited Balance\n";
                fcus << Account_No << "," << IFSC_Code << "," << fName << "," << lName << "," << Age << "," << Gender << "," << Mobile_No << "," << Address << "," << pass << "," << Total_bal << "," << Credit_bal << "," << Deposit_bal << "\n";
            }
            else
            {
                fcus << Account_No << "," << IFSC_Code << "," << fName << "," << lName << "," << Age << "," << Gender << "," << Mobile_No << "," << Address << "," << pass << "," << Total_bal << "," << Credit_bal << "," << Deposit_bal << "\n";
            }
        }
        else
        {
            ofstream file("./data_files/customer.csv");
            if (file.fail())
            {
                cout << "\n\n\t\tFile Opened Fail!..." << endl;
                usleep(1000000);
                admin ad;
                ad.adminAdd();
            }
            file << "AccountNo, IFSC Code, First Name, Last Name, Age, Gender, Mobile No, Address, Password, Total Balance, Credited Balance, Debited Balance\n";
            file << Account_No << "," << IFSC_Code << "," << fName << "," << lName << "," << Age << "," << Gender << "," << Mobile_No << "," << Address << "," << pass << "," << Total_bal << "," << Credit_bal << "," << Deposit_bal << "\n";

            file.close();
        }

        cout << "\n\n\t\t\tInformation Saved successfully...";
    }

    fcus.close();
}

void customer::perData()
{
    ifstream fin;
    fin.open("./data_files/customer.csv", ios::in);
    if (fin.fail())
    {
        cout << "\n\n\t\tFiles opened failed!" << endl;
        usleep(1000000);
        admin ad;
        ad.adminAdd();
    }
    else if (fin.is_open())
    {
        string acc;

        cout << "\n\n\t\tEnter Customer Account No :- ";
        cin >> acc;

        int count = 0;

        string line, word, temp;
        vector<string> data;

        while (getline(fin, line))
        {
            data.clear();

            stringstream s(line);
            while (getline(s, word, ','))
            {
                data.push_back(word);
            }

            temp = data[0];
            // cout << temp << endl;

            if (acc == temp)
            {
                system("clear");
                headerTitle();
                // Print the found data
                count = 1;
                cout << "\n\n\t\t\t\tCUSTOMER DETAILS\n\n";
                cout << "\t\tAccount No :- " << data[0];
                cout << "\n\t\tIFSC Code :- " << data[1];
                cout << "\n\t\tName :- " << data[2] << " " << data[3];
                cout << "\n\t\tAge :- " << data[4];
                cout << "\n\t\tGender :- " << data[5];
                cout << "\n\t\tMobile No :- " << data[6];
                cout << "\n\t\tCity :- " << data[7];
                cout << "\n\t\tTotal Balance :- " << data[9];
                cout << "\n\t\tCredit Balance :- " << data[10];
                cout << "\n\t\tDebit Balance :- " << data[11];
                cout << "\n";
                break;
            }
        }
        fin.close();
        if (count == 0)
        {
            cout << "\n\t\t\tRecord not found\n";
        }
        getchar();
    }
}

void customer::allData()
{
    ifstream fin;
    fin.open("./data_files/customer.csv", ios::in);
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
        // getline(fin, line);

        cout << "\n\n\t\t\t\tALL CUSTOMER DATA\n\n\n";
        while (getline(fin, line))
        {
            cout << line << endl;
        }
        cout << "\n";
        fin.close();
        getchar();

        cout << "\n\t\tPress any key for back...\t";
        getchar();
        usleep(1000000);
    }
}

void customer::login()
{
b:
    system("clear");
    headerTitle();

    cout << "\n\n\t\tHave an Account Already? (Y/N) : ";
    cout << "\n\n\t\tEnter Here :- ";
    char ch;
    cin >> ch;

    if (ch == 'Y' || ch == 'y')
    {
        system("clear");
        headerTitle();

        customer cs;
        cs.cuLogin();
    }
    else if (ch == 'N' || ch == 'n')
    {
        system("clear");
        headerTitle();

        customer cs;
        cs.input();
    }
    else
    {
        cout << "\n\t\tPlease, Choose Right Option...";
        usleep(2000000);
        goto b;
    }

    getchar();
}

void customer::cuLogin()
{
repeat:
    string original_Id, original_Password;
    string temp_Id, temp_Password;

    ifstream fin;
    fin.open("./data_files/customer.csv", ios::in);
    if (fin.fail())
    {
        cout << "\n\tFile failed to open. Please register fisrt then Login." << endl;
        usleep(1000000);
        customer cs;
        cs.login();
    }

    cout << "\n\n\t\tEnter your Account No : ";
    cin >> temp_Id;
    cout << "\n\t\tEnter your Password : ";
    cin >> temp_Password;

    vector<vector<string>> data;

    string line, word;

    while (getline(fin, line))
    {
        vector<string> row;
        // cout << "line" << line << endl;

        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
            // cout << "word " << word;
        }

        data.push_back(row);
    }

    bool login_success = false;
    string str;
    for (int i = 0; i < data.size(); i++)
    {
        // cout << data[i][0] << " " << data[i][8] << endl;
        // cout << temp_Id << " " << temp_Password << endl;

        if (data[i][0] == temp_Id && data[i][8] == temp_Password)
        {
            login_success = true;
            str = data[i][0];
            break;
        }
    }

    fin.close();

    if (login_success)
    {
        cout << "\n\t\t\t\tLogin successful\n\n";

        usleep(1000000);

        customer cs;
        cs.doCustomer(str);
    }
    else
    {
        cout << "\n\tWrong Id and Password, Please try again. \n\n";
        goto repeat;
    }
}

void customer::doCustomer(string acno)
{
a:
    system("clear");
    headerTitle();

    cout << "\n\n\n\t\tPlease, Choose from the following Option:\n";
    cout << "\n\t=========================================================";
    cout << "\n\t||               [1] Profile                           ||";
    cout << "\n\t||               [2] Credited Balance                  ||";
    cout << "\n\t||               [3] Debited Balance                   ||";
    cout << "\n\t||               [4] Exit                              ||";
    cout << "\n\t=========================================================";

    cout << "\n\n\n\t\t\tEnter a number :- ";
    int i;
    cin >> i;

    if (i == 1)
    {
        ifstream fin;
        fin.open("./data_files/customer.csv", ios::in);
        if (fin.fail())
        {
            cout << "\n\n\t\tFiles opened failed!" << endl;
            usleep(1000000);
            admin ad;
            ad.adminAdd();
        }
        else if (fin.is_open())
        {
            int count = 0;

            string line, word, temp;
            vector<string> data;

            while (getline(fin, line))
            {
                data.clear();

                stringstream s(line);
                while (getline(s, word, ','))
                {
                    data.push_back(word);
                }

                temp = data[0];
                // cout << temp << endl;

                if (acno == temp)
                {
                    system("clear");
                    headerTitle();
                    // Print the found data
                    count = 1;
                    cout << "\n\n\t\t\t\tCUSTOMER DETAILS\n\n";
                    cout << "\t\tAccount No :- " << data[0];
                    cout << "\n\t\tIFSC Code :- " << data[1];
                    cout << "\n\t\tName :- " << data[2] << " " << data[3];
                    cout << "\n\t\tAge :- " << data[4];
                    cout << "\n\t\tGender :- " << data[5];
                    cout << "\n\t\tMobile No :- " << data[6];
                    cout << "\n\t\tCity :- " << data[7];
                    cout << "\n\t\tTotal Balance :- " << data[9];
                    cout << "\n\t\tCredit Balance :- " << data[10];
                    cout << "\n\t\tDebit Balance :- " << data[11];
                    cout << "\n";
                    break;
                }
            }
            fin.close();
            if (count == 0)
            {
                cout << "\n\t\t\tRecord not found\n";
            }
        }

        getchar();
        cout << "\n\n\t\tPress any key for back....\t";
        getchar();
        goto a;
    }
    else if (i == 2)
    {
        system("clear");
        headerTitle();

        customer cs;
        cs.creditBal(acno);

        cout << "\n\n\t\tPress any key for back....\t";
        getchar();
        goto a;
    }
    else if (i == 3)
    {
        system("clear");
        headerTitle();

        customer cs;
        cs.debitBal(acno);

        cout << "\n\n\t\tPress any key for back....\t";
        getchar();
        goto a;
    }
    else if (i == 4)
    {
        rlPage();
    }
    else
    {
        getchar();
        cout << "\n\t\tPlease, Choose Right Option...";
        usleep(2000000);
        goto a;
    }
}

void customer::creditBal(string acno)
{
    fstream fin, fout;
    fout.open("./data_files/temp.csv", ios::out);
    fin.open("./data_files/customer.csv", ios::in);
    if (fin.fail())
    {
        cout << "\n\n\t\tFiles opened failed!" << endl;
        usleep(1000000);
        customer cs;
        cs.doCustomer(acno);
    }

    if (fin.is_open())
    {
        vector<vector<string>> data;

        string line, word;

        while (getline(fin, line))
        {
            vector<string> row;
            // cout << "line" << line << endl;

            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            data.push_back(row);
        }

        // for (auto row : data)
        // {
        //     for (auto cell : row)
        //     {
        //         cout << cell << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "\n\n";

        cout << "\n\n\t\tEnter Credit Amount :- ";
        string am;
        cin >> am;

        vector<vector<string>> val;

        val = data;

        for (int i = 0; i < val.size(); i++)
        {
            for (int j = 0; j < val[i].size(); j++)
            {
                string old = acno;
                if (val[i][j] == old)
                {
                    string v = val[i][9];
                    int v1 = atoi(v.c_str());
                    int am1 = atoi(am.c_str());
                    int t = am1 + v1;
                    string t1 = to_string(t);
                    val[i][9] = t1;

                    string a = val[i][10];
                    int a1 = atoi(a.c_str());
                    // int am1 = atoi(am.c_str());
                    int c = am1 + a1;
                    string c1 = to_string(c);
                    val[i][10] = c1;

                    cout << "\n\n\t\tTotal Amount :- " << val[i][9];
                    cout << "\n\n\t\tTotal Credited Amount :- " << val[i][10];
                }
            }
        }

        for (int i = 0; i < val.size(); i++)
        {
            for (int j = 0; j < val[i].size(); j++)
            {
                fout << val[i][j] << ",";
            }
            fout << endl;
        }
    }
    fin.close();
    remove("./data_files/customer.csv");
    rename("./data_files/temp.csv", "./data_files/customer.csv");

    getchar();
}

void customer::debitBal(string acno)
{
    fstream fin, fout;
    fout.open("./data_files/temp.csv", ios::out);
    fin.open("./data_files/customer.csv", ios::in);
    if (fin.fail())
    {
        cout << "\n\n\t\tFiles opened failed!" << endl;
        usleep(1000000);
        customer cs;
        cs.doCustomer(acno);
    }

    if (fin.is_open())
    {
        vector<vector<string>> data;

        string line, word;

        while (getline(fin, line))
        {
            vector<string> row;
            // cout << "line" << line << endl;

            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            data.push_back(row);
        }

        // for (auto row : data)
        // {
        //     for (auto cell : row)
        //     {
        //         cout << cell << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "\n\n";

        cout << "\n\n\t\tEnter Debit Amount :- ";
        string am;
        cin >> am;

        vector<vector<string>> val;

        val = data;

        for (int i = 0; i < val.size(); i++)
        {
            for (int j = 0; j < val[i].size(); j++)
            {
                string old = acno;
                if (val[i][j] == old)
                {
                    int AM = atoi(am.c_str());
                    int dd = atoi(val[i][9].c_str());
                    if (AM > dd)
                    {
                        cout << "\n\n\t\tInsufficient Balance (``The account balance is lower than the amount drawn``)";
                        cout << "\n\n\t\tTotal Amount :- " << val[i][9];
                        getchar();
                        cout << "\n\n\t\tPress any key for back....\t";
                        getchar();
                        usleep(1000000);

                        customer cs;
                        cs.doCustomer(acno);
                    }
                    else
                    {

                        string v = val[i][9];
                        int v1 = atoi(v.c_str());
                        int am1 = atoi(am.c_str());
                        int t = v1 - am1;
                        string t1 = to_string(t);
                        val[i][9] = t1;

                        string b = val[i][11];
                        int b1 = atoi(b.c_str());
                        // int ab1 = atoi(am.c_str());
                        int d = am1 + b1;
                        string d1 = to_string(d);
                        val[i][11] = d1;

                        cout << "\n\n\t\tTotal Amount :- " << val[i][9];
                        cout << "\n\n\t\tTotal Debited Amount :- " << val[i][11];
                    }
                }
            }
        }

        for (int i = 0; i < val.size(); i++)
        {
            for (int j = 0; j < val[i].size(); j++)
            {
                fout << val[i][j] << ",";
            }
            fout << endl;
        }
    }
    fin.close();
    remove("./data_files/customer.csv");
    rename("./data_files/temp.csv", "./data_files/customer.csv");

    getchar();
}