#include <iostream>
#include <string>
#include <windows.h>

#include "petshop.h"

double checkoutList() {
    int p_count = 0, count = 0;
    double total = 0, money;

    displayMenu();
    
    cout << "┃\t\t\t\t\t\t\t\t      Checkout        \t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\tProduct Name\t\t\t\t┃\t\t  Quantity      \t┃\t      Price  \t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;

    // counter for number of product in user's cart
    for (int j = 0; j < checkouts.size(); j++) {
        p_count++;
    }

    // display user's product in cart
    for (int i = 0; i < checkouts.size(); i++) {
        int p_num = checkouts[i].product;

        total += (products[p_num].price * checkouts[i].quantity);

        cout << "┃\t\t\t[" << p_num << "] " << products[p_num].name << "\t\t\t";

        if (products[p_num].name.length() <= 10) cout << "\t\t";
        else if (products[p_num].name.length() <= 19 && p_num < 10) cout << "\t";
        else if (products[p_num].name.length() <= 18 && p_num >= 10) cout << "\t";

        cout << "┃\t\t     " << checkouts[i].quantity << "   \t\t┃\t      ₱ " << products[p_num].price << "   \t\t┃" << endl;

        string details = products[p_num].animal + "\'s " + products[p_num].category;

        cout << "┃\t\t\t  ✱  " << details << "     \t\t";

        if (details.length() <= 10) cout << "\t\t";
        else if (details.length() <= 18 && p_num >= 10) cout << "\t";

        cout << "┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
                
        count++; // increment for separation line
                
        // separation for multiple product in cart
        if (count > 0 && p_count != count) {
            cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
            cout << "┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃" << endl;
            cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
        }
    }

    total += 10; // add system fee to total price

    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
    cout << "┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃" << endl;
    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
    cout << "┃\t\t\t\tSystem Fee\t\t\t\t┃\t\t\t\t\t┃\t      ₱ 10   \t\t┃" << endl;
    cout << "┃\t\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t" << checkouts[0].date << "\t\t\t\t\t\t\tTotal:\t\t┃\t     ₱ " << total << "  \t\t┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl << endl;

    return total;
}