#include <iostream>
#include <string>
#include <windows.h>

#include "petshop.h"

using namespace std;

void displayMenu() {
    system("cls");
    SetConsoleOutputCP(CP_UTF8); // line of code to print unicode/special/emoji characters

    // add condition when adding colors when menu is selected

    string account;

    if (loginStatus) {
        for (int i = 0; i < accounts.size(); i++) {
            if (loginEmail == accounts[i].email) { // display username of user when login
                account = accounts[i].username;
                break;
            }
        }

    } else account = "Account";

    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
    cout << "┃\t\t\t\t██████╗░███████╗████████╗░░███████╗██╗░░██╗██████╗░██████╗░███████╗░██████╗░██████╗\t\t\t\t┃" << endl;
    cout << "┃\t\t\t\t██╔══██╗██╔════╝╚══██╔══╝░░██╔════╝╚██╗██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝\t\t\t\t┃" << endl;
    cout << "┃\t\t\t\t██████╔╝█████╗░░░░░██║░░░░░█████╗░░░╚███╔╝░██████╔╝██████╔╝█████╗░░╚█████╗░╚█████╗░\t\t\t\t┃" << endl;
    cout << "┃\t\t\t\t██╔═══╝░██╔══╝░░░░░██║░░░░░██╔══╝░░░██╔██╗░██╔═══╝░██╔══██╗██╔══╝░░░╚═══██╗░╚═══██╗\t\t\t\t┃" << endl;
    cout << "┃\t\t\t\t██║░░░░░███████╗░░░██║░░░░░███████╗██╔╝╚██╗██║░░░░░██║░░██║███████╗██████╔╝██████╔╝\t\t\t\t┃" << endl;
    cout << "┃\t\t\t\t╚═╝░░░░░╚══════╝░░░╚═╝░░░░░╚══════╝╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚═════╝░╚═════╝░\t\t\t\t┃" << endl;
    cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t\t\t\t\t┃" << endl;

    if (loginEmail == "admin") { //menu of admin
        cout << "┃\t\t\t[S] Search\t[A] ";

        if (loginStatus) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
        cout << account ;
        
        // Reset the text color to the default
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

        cout << "\t\t\t┃\t\t[C] Accounts\t[I] Products\t[O] Checkouts\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        
    } else { //menu of customer
        cout << "┃\t\t[S] Search\t[A] ";
        
        if (loginStatus) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
        cout << account ;
        
        // Reset the text color to the default
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

        cout << "\t[C] Cart\t\t┃\t[H] Home\t[F] Foods\t[Q] Equipment\t[M] Medicine\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    }
}