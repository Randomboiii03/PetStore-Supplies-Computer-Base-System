#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <type_traits>

#include "petshop.h"

using namespace std;

template <typename T>
typename enable_if<is_same<T, Account>::value, vector<T>>::type
search(const vector<T>& items, const string& SearchTerm);

void searchAccounts() {
    string searchTerm, choose;

    displayMenu();

    cin.clear(); // clear input
    cin.ignore(LONG_MAX, '\n'); // ignore any error
    
    cout << "\t\tEnter a search term:  ";
    getline(cin, searchTerm);

    vector<Account> results = search<Account>(accounts, searchTerm);
                
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\tUsername\t\t┃\t\t\t    Email    \t\t\t┃\t  Status\t┃\t  Petcoin\t┃" << endl;

    if (!results.empty()) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t┃\t\t\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;

        //displaying search results
        for (int i = 0; i < results.size(); i++) {
            for (int j = 1; j < accounts.size(); j++) {
                if (results[i].email == accounts[j].email) {
                    cout << "┃\t    [" << j << "] " << accounts[j].username << "    ";

                    if (accounts[j].username.length() <= 10) cout << "\t\t";
                    else if (accounts[j].username.length() <= 19 && j < 10) cout << "\t";
                    else if (accounts[j].username.length() <= 18 && j >= 10) cout << "\t";
                    
                    cout << "┃\t\t" << accounts[j].email;

                    if (accounts[j].email.length() < 24) cout << "\t\t\t";
                    else if (accounts[j].email.length() < 32) cout << "\t\t";
                    else cout << "\t";

                    if (accounts[j].status) cout << "┃\t  Banned\t┃";
                    else cout << "┃\t  Active\t┃";

                    if (accounts[j].money == 100000) cout << "\t" << accounts[j].money;
                    else cout << "\t" << accounts[j].money << "\t";

                    if (accounts[j].notApproved > 0) cout << "  📩\t┃" << endl; // if there is need of approval for petcoin an icon will display
                    else cout << "  \t┃" << endl;

                    break;
                }
            }
        }

        cout << "┃\t\t\t\t\t┃\t\t\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    } else {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\tNo result for: " << searchTerm << "\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }

    cout << "\t\t☛ Input [option]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuAdmin(choose);
        searchAccounts();

    } else if (checkInput(choose) == "number" && accounts.size() > stoi(choose) && stoi(choose) < 1) {
        editAccount(stoi(choose));

    } else {
        invalidInput();
        searchAccounts();
    }    
}

template <typename T>
typename enable_if<is_same<T, Account>::value, vector<T>>::type
search(const vector<T>& items, const string& SearchTerm) {
    vector<T> results;

    // convert the search term to lower case
    string lowerCaseSearchTerm = SearchTerm;
    transform(lowerCaseSearchTerm.begin(), lowerCaseSearchTerm.end(), lowerCaseSearchTerm.begin(), ::tolower);
        
    for (const auto& account : items) {

        // ccnvert the accounts username, email and status to lower case
        string lowerCaseUsername = account.username;
        transform(lowerCaseUsername.begin(), lowerCaseUsername.end(), lowerCaseUsername.begin(), ::tolower);
        string lowerCaseEmail = account.email;
        transform(lowerCaseEmail.begin(), lowerCaseEmail.end(), lowerCaseEmail.begin(), ::tolower);
        
        string lowerCaseStatus;

        if (account.status) lowerCaseStatus = "Banned";
        else lowerCaseStatus = "Active";
        
        transform(lowerCaseStatus.begin(), lowerCaseStatus.end(), lowerCaseStatus.begin(), ::tolower);

        // search the lower case version of the account username, email and status
        if (contains(lowerCaseUsername, lowerCaseSearchTerm) ||
            contains(lowerCaseEmail, lowerCaseSearchTerm) ||
            contains(lowerCaseStatus, lowerCaseSearchTerm)) {
            results.push_back(account);
        }
    }

    return results;
}