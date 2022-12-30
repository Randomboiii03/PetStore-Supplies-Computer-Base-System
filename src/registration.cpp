#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

#include "petshop.h"

using namespace std;

void registration() {
    string email, username, password;
    int choose;

    cout << username;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t    𝗥 𝗘 𝗚 𝗜 𝗦 𝗧 𝗥 𝗔 𝗧 𝗜 𝗢 𝗡  \t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

    cout << "\t\t\t\t\t\t[option] Username: ";
    cin >> username;

    if (checkInput(username) == "alpha" && username.length() == 1) {
        transform(username.begin(), username.end(), username.begin(), ::tolower);

        menuCustomer(username);
        registration();

    } else {
        // add validation for username here

        cout << "\t\t\t\t\t\t\t    Email: ";
        cin >> email;

        // add validation for email here

        cout << "\t\t\t\t\t\t\t Password: ";
        cin >> password;

        // add validation for password & confirm password here
        
        cout << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t[1] Register\t\t\t\t┃\t\t\t\t[0] Clear\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    
        cout << "\t\t☛ Input option: ";
        cin >> choose;

        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

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