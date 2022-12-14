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

    cout << "â\t\t\t\t\t\t\t\t ğ£ ğ¥ ğ¢ ğ ğ ğ ğ \t\t\t\t\t\t\t\tâ" << endl;
    cout << "â£ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ«" << endl << endl;

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
        cout << "â£ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ«" << endl;
        cout << "â\t\t\t\t\t\t\t\t   [L] Logout     \t\t\t\t\t\t\t\tâ" << endl;
        cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;

    } else {
        cout << "\t\t\t\t\t\t\t     Petcoin: " << accounts[accNumber].money << endl << endl;

        cout << "â£ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ³ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ«" << endl;
        cout << "â\t\t\t\t[+] Add Petcoin\t\t\t\tâ\t\t\t\t  [L] Logout  \t\t\t\tâ" << endl;
        cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ»ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;
    }

    cout << "\t\tâ To edit credentials, choose a number." << endl;
    cout << "\t\tâ Input [option]: ";
    cin >> choose;

    cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;

    if (loginEmail != "admin" && choose == "+") {
        displayMenu();

        cout << "â\t\t\t\t\t\t\t\tğ ğ ğ  ğ£ ğ ğ§ ğ ğ¢ ğ ğ¡\t\t\t\t\t\t\tâ" << endl;
        cout << "â£ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ«" << endl << endl;

        if (accounts[accNumber].notApproved != 0) {
            cout << "You still have " << accounts[accNumber].notApproved << " Petcoin still in queue for approval." << endl;
            Sleep(3000);

            accountProfile();

        } else {
            cout << "\t\t\t\t\t\t\t Petcoin: " << accounts[accNumber].money << endl;
            cout << "\t\t\t\t\t\tHow much to cash in: ";
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

        } else if (money > 0 && money <= 100000 && (money + accounts[accNumber].money) <= 100000) {

            cout << endl;
            cout << "â£ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ³ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ«" << endl;
            cout << "â\t\t\t\t[1] Save\t\t\t\tâ\t\t\t\t[0] Cancel\t\t\t\tâ" << endl;
            cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ»ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;

            cout << "\t\tâ Input option: ";
            cin >> choose1;

            cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;

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
            cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;
            cout << "\t\tMoney must not less than 0 or greater than 100k." << endl;
            Sleep(2000);
            
            cout << "\t\tCanceling process...";
            Sleep(2000);

            accountProfile();
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
                cout << "â\t\t\t\t\t\t\t\tğ ğ ğ ğ§  ğ¨ ğ¦ ğ ğ¥ ğ¡ ğ ğ  ğ\t\t\t\t\t\tâ" << endl;
                cout << "â£ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ«" << endl << endl;
                cout << "\t\t\t      Old username (must be at least 8 char): " << accounts[accNumber].username << endl;
                cout << "\t\t\t\t\t\t  Enter new username: ";
                break;

            case 2:
                cout << "â\t\t\t\t\t\t\t\tğ ğ ğ ğ§  ğ£ ğ ğ¦ ğ¦ ğª ğ¢ ğ¥ ğ\t\t\t\t\t\tâ" << endl;
                cout << "â£ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ«" << endl << endl;
                cout << "\t     Old Password (must be at least 6 char and alphanumeric): " << accounts[accNumber].password << endl;
                cout << "\t\t\t\t\t\t  Enter new password: ";
                break;
        }

        cin >> temp;

        cout << endl;
        cout << "â£ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ³ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ«" << endl;
        cout << "â\t\t\t\t[1] Save\t\t\t\tâ\t\t\t\t[0] Cancel\t\t\t\tâ" << endl;
        cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ»ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;

        cout << "\t\tâ Input option: ";
        cin >> choose1;

        cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;

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
                    break;
                
                case 1:
                    if (stoi(choose) == 1) {
                        if (temp.length() < 8) {
                            cout << "\t\tUsername must be at least 8 characters." << endl;

                        } else { // change username
                            cout << "\t\tApplying changes...";
                            accounts[accNumber].username = temp;
                        }

                    } else if (stoi(choose) == 2) { 
                        if (temp.length() < 6) { // Validate password length
                            cout << "\t\tPassword must be at least 6 characters." << endl;

                        } else if (checkInput(temp) != "invalid") { // Validate password for alphanumeric characters
                            cout << "\t\tPassword must contain only alphanumeric characters." << endl;
                        
                        } else { // change password
                            accounts[accNumber].password = temp;
                            cout << "\t\tApplying changes...";
                        }
                    }
                    break;
                
                default:
                    invalidInput();

                    cout << "\t\tCanceling process...";
                    break;
            }

            Sleep(2000);
            accountProfile();
        }

    } else {
        invalidInput();
        accountProfile();
    }
}