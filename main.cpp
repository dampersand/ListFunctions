#include <iostream>
#include "dlist.cpp"
#include "RPN.h"

using namespace std;

int main()
{

    int userIn = 0;
    cout << "Select your front-end.\n" << "[1] Reverse Polish Notation calculator\n[2] Not yet defined.\n>";
    cin >> userIn;

    switch(userIn)
    {
        case 1:
            RPN();
            break;
    }


    return 0;
}
