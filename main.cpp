#include <iostream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

void displayMenu();
void menu();
void login();
void registration();
void accountProfile();
void homeAdmin();
void menuAdmin();
void viewAccounts();
void viewInventory();
void viewCheckouts();
void homeCustomer();
void search();
void foods();
void equipments();
void medicine();
void viewItem();
void cart();
void checkout();

struct Account {
    string username;
    string email;
    string password;
};

struct Product {
    string name;
    string category;
    string description;
    double price;
    int stock;
};

vector<Account> accounts;
vector<Product> products;

bool loginStatus = false;
string loginEmail = "";

void displayMenu() {
    system("cls");

    if (loginEmail == "admin") {
        cout << "+============================================================+" << endl;
        cout << "\t [S] Search \t [A] Account" << endl;
        cout << "+============================================================+" << endl;
        cout << "\t [C] Accounts \t [I] Items \t [O] Checkouts" << endl;
        cout << "+============================================================+" << endl;
        
    } else {
        cout << "+============================================================+" << endl;
        cout << "\t [S] Search \t [A] Account \t [C] Cart" << endl;
        cout << "+============================================================+" << endl;
        cout << "\t [F] Foods \t [Q] Equipment \t [M] Medicine" << endl;
        cout << "+============================================================+" << endl;
    }
}

bool checkAccount(string accountType) {
    return accountType.empty();
}

void menuCustomer(string choose) {

    if (choose == "S" || choose == "s") {
        search();

    } else if (choose == "A" || choose == "a") {
        if (!loginStatus) login();
        else accountProfile();

    } else if (choose == "C" || choose == "c") {
        if (!loginStatus) login();
        else cart();

    } else if (choose == "F" || choose == "f") {
        foods();

    } else if (choose == "Q" || choose == "q") {
        equipments();

    } else if (choose == "M" || choose == "m") {
        medicine();

    } else {
        cout << "Invalid input, please try again";
        Sleep(3000);

        displayMenu();

        homeCustomer();
    }
}

void menuAdmin(string choose) {

    if (choose == "S" || choose == "s") {
        search();

    } else if (choose == "A" || choose == "a") {
        accountProfile();

    } else if (choose == "C" || choose == "c") {
        viewAccounts();

    } else if (choose == "I" || choose == "i") {
        viewInventory();

    } else if (choose == "O" || choose == "o") {
        viewCheckouts();

    } else {
        cout << "Invalid input, please try again";
        Sleep(3000);

        displayMenu();

        homeAdmin();
    }
}

void login() {
    string email, password;
    int temp;

    displayMenu();

    cout << "[R] No Account? Register Now!" << endl;
    cout << "\t\t\t LOGIN" << endl;
    cout << "Email: ";
    cin >> email;

    if (email == "R" || email == "r") {
        registration();

    } else if (email.length() == 1) {
        menuCustomer(email);

    } else {
        cout << "Password: ";
        cin >> password;
        cout << "+============================================================+" << endl;
        cout << "\t\t [1] Login \t [0] Clear" << endl;
        cin >> temp;
        cout << "+============================================================+" << endl;

        switch(temp) {
            case 0:
                cout << "Clearing fields...";
                Sleep(3000);

                login();
                break;
            
            case 1:
                {
                    cout << "Logging In..." << endl;
                    Sleep(3000);

                    // Iterate over registered users to find a match
                    bool found = false;
                    for (const auto& account : accounts) {
                        if (email == account.email && password == account.password) {
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        // User's credentials did not match any registered users
                        cout << "Invalid email address or password." << endl;
                        Sleep(2000);

                        login();

                    } else {
                        loginStatus = true;
                        loginEmail = email;

                        cout << "Login successful!";
                        Sleep(2000);

                        if (loginEmail == "admin") homeAdmin();
                        else homeCustomer();
                    }
                }
                break;
            
            default:
                cout << "Invalid input";
                Sleep(1000);

                cout << "Clearing fields...";
                Sleep(2000);

                login();
                break;
        }
    }
}

void registration() {
    string email, username, password;
    int temp;

    displayMenu();

    cout << "\t\t\t REGISTRATION" << endl;
    cout << "Username: ";
    cin >> username;

    if (username.length() == 1) {
        menuCustomer(username);

    } else {
        cout << "Email: ";
        cin >> email;
        cout << "Password: ";
        cin >> password;
        cout << "+============================================================+" << endl;
        cout << "\t\t [1] Register \t [0] Clear" << endl;
        cin >> temp;
        cout << "+============================================================+" << endl;

        switch(temp) {
            case 0:
                cout << "Clearing fields...";
                Sleep(3000);

                registration();
                break;
            
            case 1:
                {
                    cout << "Registering..." << endl;
                    Sleep(3000);

                    // Check if the email address is already registered
                    bool found = false;
                    for (const auto& account : accounts) {
                        if (email == account.email) {
                            // Email address is already registered
                            cout << "That email address is already registered. Please try again." << endl;
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        // Add the user's information to the vector
                        accounts.push_back({username, email, password});

                        cout << "Registration successful!";
                        Sleep(2000);

                        login();

                    } else {
                        Sleep(2000);
                        registration();
                    }
                }
                break;
            
            default:
                cout << "Invalid input...";
                Sleep(1000);

                cout << "Clearing fields...";
                Sleep(2000);

                registration();
                break;
        }
    }
}

void accountProfile() {
    displayMenu();

    cout << "\t\t\t PROFILE" << endl;
    for (const auto& account : accounts) {
        if (loginEmail == account.email) {
            cout << "Username: " << account.username << endl;
            cout << "Email: " << account.email << endl;
            cout << "Password: " << account.password << endl;
            break;
        }
    }
    

}

void homeAdmin() {
    viewAccounts();
}

void viewAccounts() {
    string choose;

    displayMenu();

    cout << "\t\t\t LIST OF ACCOUNTS" << endl;

    if (accounts.size() > 1) {
        for (int i = 1; i < accounts.size(); i++) {
            cout << "[" << i << "] " << accounts[i].email;
        }

    } else {
        cout << "No account is registered yet!";
    }

    cin >> choose;
    menuAdmin(choose);
}

void viewInventory() {
    string choose;

    displayMenu();

    cout << "\t\t\t LIST OF ITEMS" << endl;

    // for (int i = 1; i < emailList.size(); i++) {
    //     cout << "[" << i << "] " << emailList[i];
    // }

    cin >> choose;
    menuAdmin(choose);
}

void viewCheckouts() {
    string choose;

    displayMenu();

    cout << "\t\t\t LIST OF CHECKOUTS" << endl;

    // for (int i = 1; i < emailList.size(); i++) {
    //     cout << "[" << i << "] " << emailList[i];
    // }

    cin >> choose;
    menuAdmin(choose);
}

void homeCustomer() {
    string choose;

    displayMenu();

    cout << "homeCustomer"; 
    cin >> choose;
    menuCustomer(choose);

}

void search() {
    displayMenu();

    cout << "search"; 

}

void foods() {
    displayMenu();

    cout << "foods"; 

}

void equipments() {
    displayMenu();

    cout << "equipments"; 

}

void medicine() {
    displayMenu();

    cout << "medicine"; 

}

void viewItem() {
    displayMenu();

    cout << "viewItem"; 

}

void cart() {
    displayMenu();

    cout << "cart"; 

}

void checkout() {
    displayMenu();

    cout << "checkout"; 

}

int main() {

    // Add the admin account to the vector
    accounts.push_back({"admin", "admin", "admin"});

    homeCustomer();
}