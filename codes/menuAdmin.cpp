#include <iostream>
#include <string>

#include "petshop.h"

using namespace std;

void menuAdmin(string choose) {

    if (choose == "s") searchAdmin();
    else if (choose == "a") accountProfile();
    else if (choose == "c") viewAccounts();
    else if (choose == "i") viewInventory();
    else if (choose == "o") viewCheckouts();
    else {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        invalidInput();
    }
}