#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

string accountType = "";

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

bool checkAccount(string accountType) {
    return accountType.empty();
}

void displayMenu() {
    system("cls");

    cout << "+============================================================+" << endl;
    cout << "\t [S] Search \t [A] Account \t [C] Cart" << endl;
    cout << "+============================================================+" << endl;
    cout << "\t [F] FOODS \t [Q] EQUIPMENT \t [M] MEDICINE" << endl;
    cout << "+============================================================+" << endl;
}

void menu(string choose) {

    if(choose == "S") {
        search();

    } else if(choose == "A") {
        if(checkAccount) login();
        else accountProfile();

    } else if(choose == "C") {
        if(checkAccount) login();
        else cart();

    } else if(choose == "F") {
        foods();

    } else if(choose == "Q") {
        equipments();

    } else if(choose == "M") {
        medicine();

    } else {
        cout << "Invalid input, please try again";
        Sleep(3000);

        displayMenu();

        if(accountType == "" || accountType == "customer") {
            homeCustomer();

        } else if(accountType == "admin") {
            homeAdmin();
        }
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

    if(email == "R") {
        registration();

    } else if(email.length() == 1) {
        menu(email);

    } else {
        cout << "Password: ";
        cin >> password;
        cout << "+============================================================+" << endl;
        cout << "[1] Login \t [0] Clear" << endl;
        cin >> temp;
        cout << "+============================================================+" << endl;

        switch(temp) {
            case 0:
                cout << "Clearing fields...";
                Sleep(3000);

                login();
                break;
            
            case 1:
                cout << "Logging In...";
                Sleep(3000);

                //check if valid acc, if valid acc check if customer or admin, then proceed to their home
                break;
            
            default:
                cout << "Invalid input";
                Sleep(1000);

                cout << "Clearing fields...";
                Sleep(3000);

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

    if(username.length() == 1) {
        menu(username);

    } else {
        cout << "Email: ";
        cin >> email;
        cout << "Password";
        cin >> password;
        cout << "+============================================================+" << endl;
        cout << "[1] Register \t [0] Clear" << endl;
        cin >> temp;
        cout << "+============================================================+" << endl;

        switch(temp) {
            case 0:
                cout << "Clearing fields...";
                Sleep(3000);

                registration();
                break;
            
            case 1:
                cout << "Registering...";
                Sleep(3000);

                //check there is same email, if none proceed registering and go to login()!
                break;
            
            default:
                cout << "Invalid input";
                Sleep(1000);

                cout << "Clearing fields...";
                Sleep(3000);

                registration();
                break;
        }
    }



}

void accountProfile() {
    displayMenu();

    cout << "account"; 

}

void homeAdmin() {
    displayMenu();

    cout << "homeAdmin"; 

}

void menuAdmin() {
    displayMenu();

    cout << "menuAdmin"; 

}

void viewAccounts() {
    displayMenu();

    cout << "viewAccounts"; 

}

void viewInventory() {
    displayMenu();

    cout << "viewInventory"; 

}

void viewCheckouts() {
    displayMenu();

    cout << "viewCheckouts"; 

}

void homeCustomer() {
    string choose;

    displayMenu();

    cout << "homeCustomer"; 
    cin >> choose;
    menu(choose);

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

    homeCustomer();
}