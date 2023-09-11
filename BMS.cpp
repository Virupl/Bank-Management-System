#include <iostream>

using namespace std;

// include file
#include "./include/Title.hh"
#include "./include/rlpage.hh"

// src files
#include "./src/Title.cpp"
#include "./src/rlpage.cpp"
#include "./src/Admin.cpp"
#include "./src/customer.cpp"

int main()
{
    system("clear");
    Title();

    rlPage();

    getchar();
    return 0;
}