#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <algorithm>

#include "petshop.h"

using namespace std;

void viewCheckouts() {
    string choose;
    double total = 0, sales = 0;

    displayMenu();

    cout << "┃\t\t\t\t\t\t\t𝗟 𝗜 𝗦 𝗧  𝗢 𝗙  𝗖 𝗛 𝗘 𝗖 𝗞 𝗢 𝗨 𝗧 𝗦\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t  Email  \t\t┃\t\tProduct Name\t\t┃     Price   \t┃\t Quantity       ┃\t  Total  \t┃" << endl;
    
    if (receipts.size() > 0) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t┃\t\t\t\t\t┃\t\t┃\t\t\t┃\t\t\t┃" << endl;

        // display receipts
        for (int i = 0; i < receipts.size(); i++) {
            // don't display date and email if previous data is same
            if (i > 0 && receipts[i].email == receipts[i - 1].email && receipts[i].date == receipts[i - 1].date) {
                cout << "┃\t\t\t\t\t";
                
            } else { // display email

                cout << "┃\t" << receipts[i].email;

                if (receipts[i].email.length() <= 15) cout << "\t\t\t";
                else if (receipts[i].email.length() <= 23) cout << "\t\t";
                else cout << "\t";
            }

            int p_num = receipts[i].product;

            cout << "┃\t✱  " << products[p_num].name; // display product

            if (products[p_num].name.length() <= 10) cout << "\t\t\t";
            else if (products[p_num].name.length() <= 20) cout << "\t\t";
            else cout << "\t";

            double p_total = receipts[i].price * receipts[i].quantity;

            cout << "┃     ₱ " << receipts[i].price << " \t┃\t   " << receipts[i].quantity << "     \t┃\t₱ " << p_total << "\t\t┃" << endl;

            total += p_total;
            sales += p_total;

            string details = products[p_num].animal + "\'s " + products[p_num].category;

            cout << "┃\t\t\t\t\t┃\t  " << details << "\t";// display other details of product

            if (details.length() <= 12) cout << "\t\t";
            else if (details.length() <= 18) cout << "\t";

            cout << "┃\t\t┃\t\t\t┃\t\t\t┃" << endl;
            cout << "┃\t\t\t\t\t┃\t\t\t\t\t┃\t\t┃\t\t\t┃\t\t\t┃" << endl;

            // display total and divider if there is multiple checkouts
            if ((receipts[i].email != receipts[i + 1].email || receipts[i].date != receipts[i + 1].date) && i != receipts.size() - 1) {
                total += 10;
                sales += 10;

                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
                cout << "┃\t\t\t\t\t\t\t\t" << receipts[i].date << "\t\t\t\t\t┃\t₱ " << total << "\t\t┃" << endl;
                cout << "┣ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┳ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┳ ━ ━ ━ ━ ━ ━ ━ ┳ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ╋ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┫" << endl;
                cout << "┃\t\t\t\t\t┃\t\t\t\t\t┃\t\t┃\t\t\t┃\t\t\t┃" << endl;

                total = 0;

            } else if (receipts[i].email == receipts[i + 1].email && receipts[i].date == receipts[i + 1].date) { // spacing if products is checkout with same email and date
                cout << "┃\t\t\t\t\t┃\t\t\t\t\t┃\t\t┃\t\t\t┃\t\t\t┃" << endl;

            } else if (i == receipts.size() - 1) { // display total for last record
                total += 10;
                sales += 10;

                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
                cout << "┃\t\t\t\t\t\t\t\t" << receipts[i].date << "\t\t\t\t\t┃\t₱ " << total << "\t\t┃" << endl;
            }
        }
        
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\tTotal Sales: ₱ " << sales << "\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    } else {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\tNo checkouts record yet!\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }

    cout << "\t\t☛ Input [option]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuAdmin(choose);
        viewCheckouts();

    } else {
        invalidInput();
        viewCheckouts();
    }
}