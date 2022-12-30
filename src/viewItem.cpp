#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

#include "petshop.h"

void viewItem(int p_num) {
    string choose;
    int quantity;

    displayMenu();

    cout << endl;
    cout << "\t\t\t\t\t\t\tProduct Name: " << products[p_num].name << endl;
    cout << "\t\t\t\t\t\t\t    Category: " << products[p_num].category << endl;
    cout << "\t\t\t\t\t\t\t      Animal: " << products[p_num].animal << endl;
    cout << "\t\t\t\t\t\t\t Description: " << products[p_num].description << endl;
    cout << "\t\t\t\t\t\t\t       Price: ₱ " << products[p_num].price << endl;
    cout << "\t\t\t\t\t\t\t       Stock: " << products[p_num].stock << " pieces" << endl << endl;

    cout << "\t\t\t\t\t\t   [option] Quantity: ";
    cin >> choose; 

    cout << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        menuCustomer(choose);
        viewItem(p_num);

    } else if (checkInput(choose) == "number") {
        if (stoi(choose) > 0 && products[p_num].stock >= stoi(choose)) {
            quantity = stoi(choose);

            cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            cout << "┃\t\t\t\t[T] Add to Cart\t\t\t\t┃\t\t\t\t[B] Buy Now\t\t\t\t┃" << endl;
            cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

            cout << "\t\t☛ Input [option]: ";
            cin >> choose;

            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

            if (checkInput(choose) == "alpha" && choose.length() == 1) {
                transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

                if (loginStatus) {
                    if (choose == "t") {
                        // check if user has the product in cart
                        auto it = find_if(carts.begin(), carts.end(), [&](const Cart& c) {
                            return c.email == loginEmail && c.product == p_num;
                        });

                        // system will attempt to add quantity to existing product in cart
                        if (it != carts.end()) { 
                            for(int i = 0; i < carts.size(); i++) {
                                if(carts[i].email == loginEmail && carts[i].product == p_num) {
                                    // user cannot add more when quantity in cart and new quantity added is more than stock of product
                                    if (carts[i].quantity + quantity > products[p_num].stock) cout << "Cannot add more because of limited stock, please try again." << endl;
                                    else { // user added quantity for the product in cart
                                        carts[i].quantity += quantity;

                                        cout << "\t\tProduct: " << products[p_num].name << " is already in the cart, and " << quantity << " more is added.";
                                    }
                                    break;
                                }
                            }
                            
                        } else { // user add product in cart if not exist
                            carts.push_back({loginEmail, p_num, quantity, false});

                            cout << "\t\tProduct: " << products[p_num].name << " is added in your cart.";
                        }

                        Sleep(3000);

                        cart();

                    } else if (choose == "b") { // direct to checkout
                        string currentTime = getCurrentTime();

                        checkouts.clear(); // clear checkout everytime user checkouts

                        checkouts.push_back({loginEmail, p_num, quantity, currentTime});
                        checkout();

                    } else {
                        menuCustomer(choose);
                        viewItem(p_num);
                    }

                } else {
                    cout << "\t\tNo account logged in yet, redirecting to LOGIN";
                    Sleep(3000);

                    login();
                }

            } else {
                cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                invalidInput();
                viewItem(p_num);
            }

        } else {
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            invalidInput();

            cout << "\t\tQuantity must not less than 0 or higher than stock number!";
            Sleep(2000);

            viewItem(p_num);
        }

    } else {
        invalidInput();
        viewItem(p_num);
    }
}