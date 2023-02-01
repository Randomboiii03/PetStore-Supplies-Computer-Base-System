#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

#include "petshop.h"

using namespace std;

void viewInventory() {
    string choose;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t𝗟 𝗜 𝗦 𝗧  𝗢 𝗙  𝐏 𝐑 𝐎 𝐃 𝐔 𝐂 𝐓 𝐒\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\tProduct Name\t\t\t┃\tCategory\t┃\t  Animal\t┃\t  Price \t┃      Stock   \t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t\t\t\t┃\t\t\t┃\t\t\t┃\t\t\t┃\t\t┃" << endl;

    // displaying all products
    for (int i = 0; i < products.size(); ++i) {
        cout << "┃\t\t[" << i << "] " << products[i].name << "\t\t";

        if (products[i].name.length() <= 10) cout << "\t\t";
        else if (products[i].name.length() <= 19 && i < 10) cout << "\t";
        else if (products[i].name.length() <= 18 && i >= 10) cout << "\t";

        cout << "┃\t" << products[i].category << "\t"; 

        if (products[i].category == "Food") cout << "\t";

        cout << "┃\t   " << products[i].animal << "   \t" << "┃\t ₱ " << products[i].price << "\t\t" << "┃      " << products[i].stock << "\t┃" << endl;
    }

    cout << "┃\t\t\t\t\t\t\t┃\t\t\t┃\t\t\t┃\t\t\t┃\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┫" << endl;

    cout << "┃\t\t\t\t\t\t\t\t    [+] ADD PRODUCT    \t\t\t\t\t\t\t\t┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t✎ To edit account, choose a number.\t\t\t\t" << endl;
    cout << "\t\t☛ Input [option]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (choose == "+") {
        addItem();
    
    } else if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuAdmin(choose);
        viewInventory();

    } else if (checkInput(choose) == "number" && stoi(choose) < products.size() && stoi(choose) >= 0) {
        editItem(stoi(choose));

    } else {
        invalidInput();
        viewInventory();
    }
}