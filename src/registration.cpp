#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <regex>

#include "petshop.h"

using namespace std;

void registration() {
    string email, username, password, cpassword;
    int choose;

    cout << username;

    displayMenu();

    cout << "â\t\t\t\t\t\t\t    ğ¥ ğ ğ ğ ğ¦ ğ§ ğ¥ ğ ğ§ ğ ğ¢ ğ¡  \t\t\t\t\t\tâ" << endl;
    cout << "â£ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ«" << endl << endl;

    cout << "\t\t        [option] Username (must be at least 8 char): ";
    cin >> username;

    if (checkInput(username) == "alpha" && username.length() == 1) {
        transform(username.begin(), username.end(), username.begin(), ::tolower);

        menuCustomer(username);
        cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;
        registration();

    } else if (username.length() < 8) {
        cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;
        cout << "\t\tUsername must be at least 8 characters." << endl;
        Sleep(2000);

        registration();

    } else {
        cout << "\t\t\t\t\t\t\t      Email: ";
        cin >> email;

        regex emailRegex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}"); // regex pattern for email address

        // Validate email using a regular expression
        if (!regex_match(email, emailRegex)) {
            cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;
            cout << "\t\tInvalid email address." << endl;
            Sleep(2000);

            registration();
        }

        cout << "\t\tPassword (must be at least 6 char and alphanumeric): ";
        cin >> password;

        // Validate password length
        if (password.length() < 6) {
            cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;
            cout << "\t\tPassword must be at least 6 characters." << endl;
            Sleep(2000);

            registration();
            
        } else if (checkInput(password) != "invalid") { // Validate password for alphanumeric characters
            cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;
            cout << "\t\tPassword must contain only alphanumeric characters." << endl;
            Sleep( 2000);

            registration();
        }

        cout << "\t\t\t\t\t\t   Confirm Password: ";
        cin >> cpassword;

        // Validate password and confirm password if same
        if (password != cpassword) {
            cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;
            cout << "\t\tPassword is not same with confirm password." << endl;
            Sleep(2000);

            registration();
        }
        
        cout << endl;
        cout << "â£ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ³ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ«" << endl;
        cout << "â\t\t\t\t[1] Register\t\t\t\tâ\t\t\t\t[0] Clear\t\t\t\tâ" << endl;
        cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ»ââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;
    
        cout << "\t\tâ Input option: ";
        cin >> choose;

        cout << "âââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââââ" << endl;

        // check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();
            
            cout << "\t\tClearing fields...";
            Sleep(2000);

            cin.clear(); // clear input
            cin.ignore(LONG_MAX, '\n'); // ignore any error

            registration();

        } else {
            switch(choose) {
                case 0:
                    cout << "\t\tClearing fields...";
                    Sleep(3000);

                    registration();
                    break;
                
                case 1:
                    {
                        cout << "\t\tRegistering..." << endl;
                        Sleep(3000);

                        // Check if the email address is already registered
                        for (const auto& account : accounts) {
                            if (email == account.email) { // Email address is already registered
                                cout << "\t\tThat email address is already registered. Please try again." << endl;
                                Sleep(2000);

                                registration();

                            } else { // Add the user's information to the vector
                                accounts.push_back({username, email, password, 0, 0, false});

                                cout << "\t\tRegistration successful!";
                                Sleep(2000);

                                login();
                            }
                            break;
                        }
                    }
                    break;
                
                default:
                    invalidInput();

                    cout << "\t\tClearing fields...";
                    Sleep(2000);

                    registration();
                    break;
            }
        }
    }
}