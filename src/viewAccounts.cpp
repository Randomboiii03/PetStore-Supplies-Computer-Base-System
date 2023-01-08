#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

#include "petshop.h"

using namespace std;

void viewAccounts() {
    string choose;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t𝗟 𝗜 𝗦 𝗧  𝗢 𝗙  𝗔 𝗖 𝗖 𝗢 𝗨 𝗡 𝗧 𝗦\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\tUsername\t\t┃\t\t\t    Email    \t\t\t┃\t  Status\t┃\t  Petcoin\t┃" << endl;

    if (accounts.size() > 1) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t┃\t\t\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;

        //displaying all accounts
        for (int i = 1; i < accounts.size(); i++) {
            cout << "┃\t    [" << i << "] " << accounts[i].username << "    ";

            if (accounts[i].username.length() <= 10) cout << "\t\t";
            else if (accounts[i].username.length() <= 19 && i < 10) cout << "\t";
            else if (accounts[i].username.length() <= 18 && i >= 10) cout << "\t";
            
            cout << "┃\t\t" << accounts[i].email << "\t\t┃\t  ";

            if (accounts[i].status) cout << "Banned\t┃";
            else cout << "Active\t┃";

            if (accounts[i].money == 100000) cout << "\t" << accounts[i].money;
            else cout << "\t" << accounts[i].money << "\t";

            if (accounts[i].notApproved > 0) cout << "  📩\t┃" << endl; // if there is need of approval for petcoin an icon will display
            else cout << "  \t┃" << endl;
        }

        cout << "┃\t\t\t\t\t┃\t\t\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    } else {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\tNo registered account yet!\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }

    cout << "\t\t✎ To edit account, choose a number.\t\t\t\t" << endl;
    cout << "\t\t☛ Input [option]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuAdmin(choose);
        viewAccounts();

    } else if (checkInput(choose) == "number" && stoi(choose) < accounts.size() && stoi(choose) > 0) {
        editAccount(stoi(choose));

    } else {
        invalidInput();
        viewAccounts();
    }
}