#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

#include "petshop.h"

void checkout() {
    string choose;
    int choose1;
    double total, money;

    checkoutList();
    
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃\t\t\t\t\t\t\t\t  MODE OF PAYMENT      \t\t\t\t\t\t\t\t┃" << endl;
    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\t\t[1] Cash\t\t\t\t┃\t\t\t\t[2] Petcoin\t\t\t\t┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t\t\t\t\t\t\t☛ Input [action]: ";
    cin >> choose;

    // check if string is inputted in an int variable
    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuCustomer(choose);
        checkout();

    } else if (checkInput(choose) == "number" && stoi(choose) >= 1 && stoi(choose) <= 2) {

        total = checkoutList();

        if (stoi(choose) == 1) cout << "\t\tMode of Payment: Cash" << endl << endl;
        else cout << "\t\tMode of Payment: Petcoin" << endl << endl;
        
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃\t\t\t\t[1] Checkout\t\t\t\t┃\t\t\t\t[0] Cancel\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

        cout << "\t\t☛ Input action: ";
        cin >> choose1;

        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

        if(cin.fail()) {
            invalidInput();

            cout << "\t\tCanceling process...";

            cin.clear(); // clear input
            cin.ignore(LONG_MAX, '\n'); // ignore any error

        } else {
            switch(choose1) {
                case 0:
                    cout << "\t\tCanceling process...";
                    break;

                case 1:
                    cout << "\t\tProcessing transaction..." << endl;
                    Sleep(3000);

                    switch(stoi(choose)) {
                        case 1:
                            cout << "\t\tHow much is your cash onhand? ";
                            cin >> money;

                            if (money >= total) {
                                dedactProduct();
                                money -= total;

                                if (money != 0) cout << "\t\tYour change is ₱ " << money << endl;
                                Sleep(1000);

                                cout << "\t\tThanks for purchasing!";

                            } else cout << "\t\tYour money is not enough for the total price you checkout, please try again.";

                            break;

                        case 2:
                            for(int i = 1; i < accounts.size(); i++) {
                                if (accounts[i].email == loginEmail) {
                                    if (accounts[i].money >= total) {
                                        cout << "\t\tThanks for purchasing!";

                                        dedactProduct();
                                        accounts[i].money -= total; // dedacting total price from petcoin

                                    } else cout << "\t\tYour Petcoin is not enough for the total price you checkout, cash in to use Petcoin.";
                                }
                            }
                            break;
                    }
                    break;

                default:
                    invalidInput();

                    cout << "\t\tCanceling process...";
                    break;
            }
        }

        Sleep(2000);
        cart();

    } else {
        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
        invalidInput();

        cout << "\t\tReseting process...";
        Sleep(2000);

        checkout();
    }
}