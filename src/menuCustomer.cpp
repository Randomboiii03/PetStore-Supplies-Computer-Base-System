#include <iostream>
#include <string>
#include <windows.h>

#include "petshop.h"

using namespace std;

void menuCustomer(string choose) {

    if (choose == "h") homeCustomer();
    else if (choose == "s") searchProducts();
    else if (choose == "a") {
        if (!loginStatus) {
            cout << "\t\tNo account logged in yet, redirecting to LOGIN";
            Sleep(3000);

            login();
        }
        else accountProfile();

    } else if (choose == "c") {
        if (!loginStatus) {
            cout << "\t\tNo account logged in yet, redirecting to LOGIN";
            Sleep(3000);

            login();
        }
        else cart();

    } else if (choose == "f") foods();
    else if (choose == "q") equipments();
    else if (choose == "m") medicine();
    else invalidInput();
}