#include <iostream>
#include <string>
#include <windows.h>
#include <iterator>
#include <algorithm>

#include "petshop.h"

void menuCart(int p_num) {
    string choose;
    int quantity;

    cout << endl;
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃           [O] De/Select for Checkout          ┃                  [D] Delete                   ┃                   [E] Edit                    ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t☛ Input option: ";
    cin >> choose; 

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (choose == "o") { //select or deselect product for checkout in user's cart
        for(int i = 0; i < carts.size(); i++) {
            if(carts[i].email == loginEmail && carts[i].product == p_num) {
                cout << "\t\tProduct: " << products[p_num].name;

                if (carts[i].status) {
                    carts[i].status = false;
                    cout << " is deselected for checkout." << endl;
                } else {
                    carts[i].status = true;
                    cout << " is selected for checkout." << endl;
                }
                break;
            }
        }

    } else if (choose == "d") { // delete product in user's cart
        carts.erase(std::remove_if(carts.begin(), carts.end(), [&](const Cart& c) -> bool {
            return c.email == loginEmail && c.product == p_num;
        }), carts.end());

        cout << "\t\tProduct: " << products[p_num].name << " is deleted in your cart.";

    } else if (choose == "e") { // edit quantity for the product in user's cart
        for(int i = 0; i < carts.size(); i++) {
            if(carts[i].email == loginEmail && carts[i].product == p_num) {
                cout << "\t\t\t\t\t\t\tOld quantity: " << carts[i].quantity << endl;
                cout << "\t\t\t\t\t\t  Enter new quantity: ";
                cin >> quantity;

                cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                
                if (quantity > products[p_num].stock) cout << "Cannot edit quantity because there is "<< products[p_num].stock << " piece/s stock left, please try again." << endl;
                else { // user edit quantity for the product
                    carts[i].quantity = quantity;

                    cout << "\t\tEditing product successful.";
                }
                break;
            }
        }

    } else invalidInput();

    Sleep(2000);
    cart();
}
