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

    cout << "┃\t\t\t\t\t\t\t\t    𝗛 𝗢 𝗠 𝗘        \t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\tProduct Name\t\t\t┃\t\tCategory\t\t┃\t  Animal      \t┃\t  Price      \t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;

    for (int i = 0; i < 10; ++i) {
        int index = getRandomNumber(products);
        
        while (selected.count(index) > 0) { // check if the generated number has been already selected
            index = getRandomNumber(products);
        }

        selected.insert(index); // inserting random number in set

        // displaying products base on numbers in set
        if (products[index].status) {
            cout << "┃\t\t[" << index << "] " << products[index].name << "\t\t";

            if (products[index].name.length() <= 10) cout << "\t\t";
            else if (products[index].name.length() <= 19 && index < 10) cout << "\t";
            else if (products[index].name.length() <= 18 && index >= 10) cout << "\t";

            cout << "┃\t\t" << products[index].category;

            if (products[index].category == "Food") cout << "\t";

            cout << "\t\t┃\t   " << products[index].animal << "     \t┃\t  ₱ " << products[index].price << "      \t┃" << endl;
        }
    }

    cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t☛ Input [option]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

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