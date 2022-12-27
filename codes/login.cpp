#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

#include "petshop.h"

using namespace std;

void login() {
    string email, password;
    int choose;

    displayMenu();
    
    cout << "┃\t\t[R] No Account? Register Now!\t\t\t      LOGIN  \t\t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

    cout << "\t\t\t\t\t\t\t[action] Email: ";
    cin >> email;

    if (checkInput(email) == "alpha" && email.length() == 1) {
        transform(email.begin(), email.end(), email.begin(), ::tolower);

        if (email == "r") {
            registration();

        } else {
            menuCustomer(email);
            login();
        }

    } else {
        cout << "\t\t\t\t\t\t\t      Password: ";
        cin >> password;
        cout << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t[1] Login\t\t\t\t┃\t\t\t\t[0] Clear\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

        cout << "\t\t☛ Input action: ";
        cin >> choose;

        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

        // check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();

            cout << "\t\tClearing fields...";
            Sleep(2000);

            cin.clear(); // clear input
            cin.ignore(LONG_MAX, '\n'); // ignore any error

            login();

        } else {
            switch(choose) {
                case 0:
                    cout << "\t\tClearing fields...";
                    Sleep(3000);

                    login();
                    break;
                    
                case 1:
                    {
                        cout << "\t\tLogging In..." << endl;
                        Sleep(3000);

                        // iterate over registered users to find a match
                        for (const auto& account : accounts) {
                            if (email == account.email && password == account.password) {

                                if (account.status) { // if true user's account is banned
                                    cout << "\t\tCannot login, your account is banned." << endl;
                                    Sleep(2000);

                                    login();

                                } else {
                                    loginStatus = true;
                                    loginEmail = email;

                                    cout << "\t\tLogin successful!";
                                    Sleep(2000);

                                    if (loginEmail == "admin") homeAdmin();
                                    else homeCustomer();
                                }
                                break;
                            }
                        }

                        // user's credentials did not match any registered users
                        cout << "\t\tInvalid email address or password." << endl;
                        Sleep(2000);

                        login();
                    }
                    break;
                    
                default:
                    invalidInput();

                    cout << "\t\tClearing fields...";
                    Sleep(2000);

                    login();
                    break;
            }
        }
    }
}