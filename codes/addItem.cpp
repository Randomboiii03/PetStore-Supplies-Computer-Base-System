#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

#include "petshop.h"

using namespace std;

void addItem() {
    string name, category, animal, description;
    double price;
    int choose, temp, stock;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t\tADD NEW PRODUCT\t\t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;
    cout << "\t\t\t\t\t  [action] Name: ";
    cin >> name;

    if (checkInput(name) == "alpha" && name.length() == 1) {
        transform(name.begin(), name.end(), name.begin(), ::tolower);

        menuAdmin(name);
        viewInventory();

    } else if (name.length() == 1) {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        invalidInput();
            
        cout << "\t\tCanceling process...";
        viewInventory();
    }

    cout << "\t⟶   [1] Food   [2] Equipment   [3] Medicine  ⟵" << endl;
    cout << "\t\t\t\t\tChoose category: ";
    cin >> temp;

    if (cin.fail() || temp > 3 || temp <= 0) {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        invalidInput();
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        cin.clear(); // clear input
        cin.ignore(LONG_MAX, '\n'); // ignore any error

        viewInventory();

    } else if (temp > 3 || temp <= 0) {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        invalidInput();
            
        cout << "\t\tCanceling process...";
        viewInventory();

    } else {
        switch(temp) {
            case 1:
                category = "Food";
                break;
            case 2:
                category = "Equipment";
                break;
            case 3:
                category = "Medicine";
                break;
        }
    }

    cout << "\t⟶   [1] Dog   [2] Cat   [3] Fish   [4] Bird  ⟵" << endl;
    cout << "\t\t\t\t\t  Choose animal: ";
    cin >> animal;

    if (cin.fail()) {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        invalidInput();
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        cin.clear(); // clear input
        cin.ignore(LONG_MAX, '\n'); // ignore any error

        viewInventory();

    } else if (temp > 4 || temp <= 0) {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        invalidInput();
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        viewInventory();

    } else {
        switch(temp) {
            case 1:
                category = "Dog";
                break;
            case 2:
                category = "Cat";
                break;
            case 3:
                category = "Fish";
                break;
            case 4:
                category = "Bird";
                break;
        }
    }

    cin.clear(); // clear input
    cin.ignore(LONG_MAX, '\n'); // ignore any error

    cout << "\t\t\t\t\t    Description: ";
    getline(cin, description);

    cout << "\t\t\t\t\t\t  Price: ";
    cin >> price;

    if (cin.fail()) {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        invalidInput();
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        cin.clear(); // clear input
        cin.ignore(LONG_MAX, '\n'); // ignore any error

        viewInventory();

    } else if (price <= 0) {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        cout << "\tPrice must not less than 1.";
        Sleep(3000);
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        viewInventory();
    } 

    cout << "\t\t\t\t\t\t  Stock: ";
    cin >> stock;

    if (cin.fail()) {
        invalidInput();
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        cin.clear(); // clear input
        cin.ignore(LONG_MAX, '\n'); // ignore any error

        viewInventory();

    } else if (stock <= 0) {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        cout << "\t\tStock must not less than 1.";
        Sleep(3000);
        
        cout << "\t\tCanceling process...";
        Sleep(2000);

        viewInventory();

    } 

    cout << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t[1] Save\t\t\t\t┃\t\t\t\t[0] Cancel\t\t\t\t┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    
    cout << "\t\t☛ Input action: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (cin.fail()) {
        invalidInput();
            
        cout << "\t\tCanceling process...";
        Sleep(2000);

        cin.clear(); // clear input
        cin.ignore(LONG_MAX, '\n'); // ignore any error

    } else {
        switch(choose) {
            case 0:
                cout << "\t\tCanceling process...";
                Sleep(3000);
                break;
                
            case 1: // adding product in the vector
                products.push_back({name, category, animal, description, price, stock, true});

                cout << "\t\tAdding product...";
                Sleep(3000);
                break;
                
            default:
                invalidInput();

                cout << "\t\tCanceling process...";
                Sleep(2000);
                break;
        }
    }

    viewInventory();
}