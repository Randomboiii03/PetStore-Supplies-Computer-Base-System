#include <iostream>
#include <string>
#include <windows.h>

#include "petshop.h"

using namespace std;

void searchAdmin() {
    int choose;
    
    displayMenu();

    cout << "┃\t\t\tSEARCH ➜\t\t\t\t[1] Accounts\t\t\t\t[2] Products\t\t\t\t┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t\t\tInput option: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (cin.fail()) {
        invalidInput();

        cout << "\t\tClearing fields...";
        Sleep(2000);

        cin.clear(); // clear input
        cin.ignore(LONG_MAX, '\n'); // ignore any error

        searchAdmin();

    } else {
        switch (choose){
            case 1: searchAccounts();
            case 2: searchProducts();
            default:
                invalidInput();
                searchAdmin();
        }
    }
}