#include <iostream>
#include <string>
#include <windows.h>

#include "petshop.h"

void dedactProduct() {
    for (const auto& checkout : checkouts) {
        for (int i = 0; i < carts.size(); i++) {
            if (carts[i].product == checkout.product && carts[i].email == loginEmail) {
                carts.erase(carts.begin() + i); // dedact products that has been checkout
                Sleep(5000);
                break;
            }
        }

        receipts.push_back({loginEmail, checkout.product, checkout.quantity, checkout.date}); // insert in reciept vector
        products[checkout.product].stock -= checkout.quantity; // dedacting stocks
    }
}