#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <set>

#include "petshop.h"

using namespace std;

void homeCustomer() {
    string choose;
    srand(time(nullptr));
    set<int> selected;

    displayMenu();

    cout << "â\t\t\t\t\t\t\t\t    ğ ğ¢ ğ  ğ        \t\t\t\t\t\t\t\tâ" << endl;
    cout << "â£ââââââââââââââââââââââââââââââââââââââââââââââââââââââââ³ââââââââââââââââââââââââââââââââââââââââ³ââââââââââââââââââââââââ³ââââââââââââââââââââââââ«" << endl;
    cout << "â\t\t\tProduct Name\t\t\tâ\t\tCategory\t\tâ\t  Animal      \tâ\t  Price      \tâ" << endl;
    cout << "â£ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ«" << endl;
    cout << "â\t\t\t\t\t\t\tâ\t\t\t\t\tâ\t\t\tâ\t\t\tâ" << endl;

    for (int i = 0; i < 10; ++i) {
        int index = getRandomNumber(products);
        
        while (selected.count(index) > 0) { // check if the generated number has been already selected
            index = getRandomNumber(products);
        }

        selected.insert(index); // inserting random number in set

        // displaying products base on numbers in set
        if (products[index].status) {
            cout << "â\t\t[" << index << "] " << products[index].name << "\t\t";

            if (products[index].name.length() <= 10) cout << "\t\t";
            else if (products[index].name.length() <= 19 && index < 10) cout << "\t";
            else if (products[index].name.length() <= 18 && index >= 10) cout << "\t";

            cout << "â\t\t" << products[index].category;

            if (products[index].category == "Food") cout << "\t";

            cout << "\t\tâ\t   " << products[index].animal << "     \tâ\t  â± " << products[index].price << "      \tâ" << endl;
        }
    }

    cout << "â\t\t\t\t\t\t\tâ\t\t\t\t\tâ\t\t\tâ\t\t\tâ" << endl;
    cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââ»ââââââââââââââââââââââââââââââââââââââââ»ââââââââââââââââââââââââ»ââââââââââââââââââââââââ" << endl;

    cout << "\t\tâ Input [option]: ";
    cin >> choose;

    cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuCustomer(choose);
        homeCustomer();

    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && stoi(choose) >= 0 && products[stoi(choose)].status) {
        viewItem(stoi(choose));

    } else {
        invalidInput();
        homeCustomer();
    }
}