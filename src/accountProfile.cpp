#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

#include "petshop.h"

using namespace std;

void accountProfile() {
    string choose, temp;
    int accNumber, choose1;
    double money;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t\t    PROFILE    \t\t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

    //display user's credentials
    for (int i = 0; i < accounts.size(); i++) {
        if (loginEmail == accounts[i].email) {

            cout << "\t\t\t\t\t\t\t       Email: " << accounts[i].email << endl;
            cout << "\t\t\t\t\t\t\t[1] Username: " << accounts[i].username << endl;
            cout << "\t\t\t\t\t\t\t[2] Password: " << accounts[i].password << endl;

            accNumber = i;
            break;
        }
    }

    if (loginEmail == "admin") {
        cout << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t   [L] Logout     \t\t\t\t\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    } else {
        cout << "\t\t\t\t\t\t\t     Petcoin: " << accounts[accNumber].money << endl << endl;

        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t[+] Add Petcoin\t\t\t\t┃\t\t\t\t  [L] Logout  \t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }

    cout << "\t\t☛ Input [action]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (loginEmail != "admin" && choose == "+") {

        cout << "┃\t\t\t\t\t\t\t\tADD PETCOIN\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

        if (accounts[accNumber].notApproved != 0) {
            cout << "You still have " << accounts[accNumber].notApproved << " Petcoin still in queue for approval." << endl;
            Sleep(3000);

            accountProfile();

        } else {
            cout << "\t\t\t\t\t\t\tHow much : ";
            cin >> money;
        }

        // check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();
            
            cout << "\t\tCanceling process...";
            Sleep(2000);

            cin.clear(); // clear input
            cin.ignore(LONG_MAX, '\n'); // ignore any error

            accountProfile();

        } else if (money > 0) {

            cout << endl;
            cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            cout << "┃\t\t\t\t[1] Save\t\t\t\t┃\t\t\t\t[0] Cancel\t\t\t\t┃" << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

            cout << "\t\t☛ Input action: ";
            cin >> choose1;

            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

            // check if string is inputted in an int variable
            if (cin.fail()) {
                invalidInput();
                
                cout << "\t\tCanceling process...";
                Sleep(2000);

                cin.clear(); // clear input
                cin.ignore(LONG_MAX, '\n'); // ignore any error

                accountProfile();

            } else {
                switch(choose1) {
                    case 0:
                        cout << "\t\tCanceling process...";
                        Sleep(3000);

                        accountProfile();
                        break;
                    
                    case 1:
                        accounts[accNumber].notApproved = money;

                        cout << "\t\tPetcoin will be added in your account, please wait for approval.";
                        Sleep(3000);

                        accountProfile();
                        break;
                    
                    default:
                        invalidInput();

                        cout << "\t\tCanceling process...";
                        Sleep(2000);

                        accountProfile();
                        break;
                }
            }

        } else {
            cout << "\t\tMoney must not less than 0.";
            Sleep(2000);
            
            cout << "\t\tCanceling process...";
            Sleep(2000);
        }
        
    } else if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        if (choose == "l") { // logout
            cout << "\t\tLogging out...";
            Sleep(3000);

            loginStatus = false;
            loginEmail = "";

            homeCustomer();

        } else {
            if (loginEmail == "admin") menuAdmin(choose);
            else menuCustomer(choose);

            invalidInput();
            accountProfile();
        }

    } else if (checkInput(choose) == "number" && stoi(choose) <= 2 && stoi(choose) > 0) {
        displayMenu();

        switch(stoi(choose)) {
            case 1:
                cout << "┃\t\t\t\t\t\t\t\tEDIT USERNAME\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;
                cout << "\t\t\t\t\t\t\tOld username: " << accounts[accNumber].username << endl;
                cout << "\t\t\t\t\t\t  Enter new username: ";
                break;

            case 2:
                cout << "┃\t\t\t\t\t\t\t\tEDIT PASSWORD\t\t\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;
                cout << "\t\t\t\t\t\t\tOld password: " << accounts[accNumber].password << endl;
                cout << "\t\t\t\t\t\t  Enter new password: ";
                break;
        }

        cin >> temp;

        cout << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t[1] Save\t\t\t\t┃\t\t\t\t[0] Cancel\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

        cout << "\t\t☛ Input action: ";
        cin >> choose1;

        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

        // check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();
            
            cout << "\t\tCanceling process...";
            Sleep(2000);

            cin.clear(); // clear input
            cin.ignore(LONG_MAX, '\n'); // ignore any error

            accountProfile();

        } else {
            switch(choose1) {
                case 0:
                    cout << "\t\tCanceling process...";
                    Sleep(3000);

                    accountProfile();
                    break;
                
                case 1:
                    if (stoi(choose) == 0) accounts[accNumber].username = temp; // change username
                    else if (stoi(choose) == 1) accounts[accNumber].password = temp; // change password

                    cout << "\t\tApplying changes...";
                    Sleep(3000);

                    accountProfile();
                    break;
                
                default:
                    invalidInput();

                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    accountProfile();
                    break;
            }
        }

    } else {
        invalidInput();
        accountProfile();
    }
}