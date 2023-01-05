#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

#include "petshop.h"

void cart() {
    string choose;
    int p_count = 0, count = 0, check_count = 0, s_count = 0;
    double total = 0;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t\t     𝗖 𝗔 𝗥 𝗧      \t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\tProduct Name\t\t\t\t┃\t\t  Quantity      \t┃\t      Price  \t\t┃" << endl;
    
    // check if user has any product in cart
    auto it = find_if(carts.begin(), carts.end(), [&](const Cart& c) {
        return c.email == loginEmail;
    });

    if (it != carts.end()) {
    
        cout << "┣━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t┃\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;

        // counter for number of product in user's cart
        for (int j = 0; j < carts.size(); j++) {
            if (carts[j].email == loginEmail) p_count++;
        }

        // display user's product in cart
        for (int i = 0; i < carts.size(); i++) {
            if (carts[i].email == loginEmail) {

                int p_num = carts[i].product;

                if (!carts[i].status) cout << "┃   ☐";
                else {
                    cout << "┃  ✅";
                    check_count++;
                    total += (products[p_num].price * carts[i].quantity);
                }

                cout << "   ┃\t\t[" << p_num << "] " << products[p_num].name << "\t\t\t";

                if (products[p_num].name.length() <= 10) cout << "\t\t";
                else if (products[p_num].name.length() <= 19 && p_num < 10) cout << "\t";
                else if (products[p_num].name.length() <= 18 && p_num >= 10) cout << "\t";

                cout << "┃\t\t     " << carts[i].quantity << "   \t\t┃\t      ₱ " << products[p_num].price << "   \t\t┃" << endl;

                string details = products[p_num].animal + "\'s " + products[p_num].category;

                cout << "┃       ┃\t\t  ✱  " << details << "     \t\t";

                if (details.length() <= 10) cout << "\t\t";
                else if (details.length() <= 18 && p_num >= 10) cout << "\t";

                cout << "┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
                
                // increment for separation line
                count++;
                
                // separation for multiple product in cart
                if (count > 0 && p_count != count) {
                    cout << "┃\t┃\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
                    cout << "┃━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃" << endl;
                    cout << "┃\t┃\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
                }
            }
        }
    
        cout << "┃\t┃\t\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t\t┃" << endl;
        
        if (check_count == 0) cout << "┗━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        else {
            cout << "┣━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            cout << "┃\t\t\t\t[O] Checkout\t\t\t\t\t\t\tTotal:\t\t┃\t     ₱ " << total << "  \t\t┃" << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        }

        cout << "\t\t✎ To de/select, edit or delete product in cart, choose the product's number." << endl;

    } else {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\tNo product in cart yet!\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }

    cout << "\t\t☛ Input [option]: ";
    cin >> choose; 
    
    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        if (choose == "o") {
            string currentTime = getCurrentTime();

            checkouts.clear(); // clear checkout everytime user checkouts

            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

            for (int i = 0; i < carts.size(); i++) {
                if (carts[i].email == loginEmail && carts[i].status) checkouts.push_back({loginEmail, carts[i].product, carts[i].quantity, currentTime});
                if (carts[i].quantity > products[carts[i].product].stock) { // product has zero or less stock than the quantity to checkout
                    cout << "\t\tProduct: " << products[carts[i].product].name << " has " << products[carts[i].product].stock << " piece/s stock left." << endl;
                    s_count++;
                }
            }

            if (checkouts.size() > 0) checkout();
            else if (s_count > 0) {
                Sleep(3000);
                cart();

            } else {
                cout << "No product/s is selected in cart yet";
                Sleep(3000);

                cart();
            }
            
        } else {
            menuCustomer(choose);
            cart();
        }
        
    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && stoi(choose) >= 0) {
        // check if user has the product in cart
        it = find_if(carts.begin(), carts.end(), [&](const Cart& c) {
            return c.email == loginEmail && c.product == stoi(choose);
        });

        if (it != carts.end()) menuCart(stoi(choose));
        else {
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            invalidInput();

            cout << "\t\tNo product number exist in your cart";
            Sleep(2000);

            cart();
        }

    } else {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        invalidInput();
        cart();
    }
}