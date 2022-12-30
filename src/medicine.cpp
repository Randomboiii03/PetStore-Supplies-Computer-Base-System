#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

#include "petshop.h"

void medicine() {
    string choose;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t\t𝗠 𝗘 𝗗 𝗜 𝗖 𝗜 𝗡 𝗘\t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\tProduct Name\t\t\t\t┃\t\t  Animal      \t\t┃\t      Price  \t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;

    // display products on category medicine
    for (int i = 0; i < products.size(); i++) {
        if (products[i].category == "Medicine" && products[i].status) {
            cout << "┃\t\t\t[" << i << "] " << products[i].name << "\t\t\t";

            if (products[i].name.length() <= 10) cout << "\t\t";
            else if (products[i].name.length() <= 19 && i < 10) cout << "\t";
            else if (products[i].name.length() <= 18 && i >= 10) cout << "\t";

            cout << "┃\t\t   " << products[i].animal << "     \t\t┃\t      ₱ " << products[i].price << "  \t\t┃" << endl;
        }
    }

    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t☛ Input [option]: ";
    cin >> choose; 

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);
        
        menuCustomer(choose);
        medicine();

    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && stoi(choose) >= 0 && products[stoi(choose)].category == "Medicine" && products[stoi(choose)].status) {
        viewItem(stoi(choose));

    } else {
        invalidInput();
        medicine();
    }
}