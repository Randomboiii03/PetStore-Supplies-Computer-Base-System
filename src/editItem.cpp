#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

#include "petshop.h"

using namespace std;

void editItem(int p_num) {
    string choose, temp;
    int choose1;

    displayMenu();

    cout << endl;
    cout << "\t\t\t\t\t\t\t[1] Product Name: " << products[p_num].name << endl;
    cout << "\t\t\t\t\t\t\t[2]    Category: " << products[p_num].category << endl;
    cout << "\t\t\t\t\t\t\t[3]      Animal: " << products[p_num].animal << endl;
    cout << "\t\t\t\t\t\t\t[4] Description: " << products[p_num].description << endl;
    cout << "\t\t\t\t\t\t\t[5]       Price: ₱ " << products[p_num].price << endl;
    cout << "\t\t\t\t\t\t\t[6]       Stock: " << products[p_num].stock << " pieces" << endl;
    cout << "\t\t\t\t\t\t\t[7]      Status: ";
    
    if (products[p_num].status) cout << "Displayed" << endl << endl;
    else cout << "Not Displayed" << endl << endl;

    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t☛ Input [option]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuAdmin(choose);
        viewInventory();

    } else if (checkInput(choose) == "number" && stoi(choose) <= 7 && stoi(choose) >= 1) {
        displayMenu();

        switch(stoi(choose)) {
            case 1:
                cout << "┃\t\t\t\t\t\t\t𝗘 𝗗 𝗜 𝗧  𝗣 𝗥 𝗢 𝗗 𝗨 𝗖 𝗧  𝗡 𝗔 𝗠 𝗘\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld product name: " << products[p_num].name << endl;
                cout << "\t\t\t\t\t\t  Enter new product name: ";
                cin >> temp;

                break;
                
            case 2:
                cout << "┃\t\t\t\t\t\t\t    𝗘 𝗗 𝗜 𝗧  𝗖 𝗔 𝗧 𝗘 𝗚 𝗢 𝗥 𝗬  \t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld category: " << products[p_num].category << endl;
                cout << "\t\t\t\t\t\t⟶   [1] Food   [2] Equipment   [3] Medicine  ⟵" << endl;
                cout << "\t\t\t\t\t\t  Enter new category: ";
                cin >> temp;

                if (checkInput(temp) == "number") {
                    if (stoi(temp) > 3 || stoi(temp) <= 0) {
                        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                        invalidInput();
                                
                        cout << "\t\tCanceling process...";
                        viewInventory();

                    } else {
                        switch(stoi(temp)) {
                            case 1:
                                temp = "Food";
                                break;
                            case 2:
                                temp = "Equipment";
                                break;
                            case 3:
                                temp = "Medicine";
                                break;
                        }
                    }

                } else {
                    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                    invalidInput();
                                
                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();
                }

                break;

            case 3:
                cout << "┃\t\t\t\t\t\t\t\t𝗘 𝗗 𝗜 𝗧  𝗔 𝗡 𝗜 𝗠 𝗔 𝗟\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld animal: " << products[p_num].animal << endl;
                cout << "\t\t\t\t\t\t⟶   [1] Dog   [2] Cat   [3] Fish   [4] Bird  ⟵" << endl;
                cout << "\t\t\t\t\t\t  Enter new animal: ";
                cin >> temp;

                if (checkInput(temp) == "number") {
                    if (stoi(temp) > 4 || stoi(temp) <= 0) {
                        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                        invalidInput();
                                
                        cout << "\t\tCanceling process...";
                        Sleep(2000);

                        viewInventory();

                    } else {
                        switch(stoi(temp)) {
                            case 1:
                                temp = "Dog";
                                break;
                            case 2:
                                temp = "Cat";
                                break;
                            case 3:
                                temp = "Fish";
                                break;
                            case 4:
                                temp = "Bird";
                                break;
                        }
                    }

                } else {
                    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                    invalidInput();
                                
                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();
                }
                break;

            case 4:
                cout << "┃\t\t\t\t\t\t\t𝗘 𝗗 𝗜 𝗧  𝗗 𝗘 𝗦 𝗖 𝗥 𝗜 𝗣 𝗧 𝗜 𝗢 𝗡\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld description: " << products[p_num].description << endl;
                cout << "\t\t\t\t\t\t  Enter new description: ";

                cin.clear(); // clear input
                cin.ignore(LONG_MAX, '\n'); // ignore any error
                getline(cin, temp);

                break;

            case 5:
                cout << "┃\t\t\t\t\t\t\t\t𝗘 𝗗 𝗜 𝗧  𝗣 𝗥 𝗜 𝗖 𝗘\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld price: " << products[p_num].price << endl;
                cout << "\t\t\t\t\t\t  Enter new price: ";
                cin >> temp;

                if (checkInput(temp) == "number" && stoi(temp) <= 0) {
                    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                    cout << "\t\tPrice must not less than 1." << endl;
                    Sleep(3000);
                                
                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();

                } else if (checkInput(temp) != "number") {
                    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                    invalidInput();
                                
                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();
                }
                break;

            case 6:
                cout << "┃\t\t\t\t\t\t\t\t𝗘 𝗗 𝗜 𝗧  𝗦 𝗧 𝗢 𝗖 𝗞\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld stock: " << products[p_num].stock << endl;
                cout << "\t\t\t\t\t\t  Enter new stock: ";
                cin >> temp;

                if (checkInput(temp) == "number" && stoi(temp) <= 0) {
                    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                    cout << "\t\tStock must not less than 1." << endl;
                    Sleep(3000);
                                
                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();

                } else if (checkInput(temp) != "number") {
                    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
                    invalidInput();
                                
                    cout << "\t\tCanceling process..." << checkInput(temp) << "trgfg";
                    Sleep(2000);

                    viewInventory();
                }
                break;

            case 7:
                cout << "┃\t\t\t\t\t\t\t\t𝗘 𝗗 𝗜 𝗧  𝗦 𝗧 𝗔 𝗧 𝗨 𝗦\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;
                    
                if (products[p_num].status) cout << "\t\t\t\t\t\t\tStatus: Display ⟶   Not Display  \t\t\t\t";
                else cout << "\t\t\t\t\t\t\tStatus: Not Display ⟶   Display  \t\t\t\t" << endl;

                break;
        }

        cout << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t[1] Save\t\t\t\t┃\t\t\t\t[0] Cancel\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

        cout << "\t\t☛ Input option: ";
        cin >> choose1;

        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

        if (cin.fail()) {
            invalidInput();
                
            cout << "\t\tCanceling process...";
            Sleep(2000);

            cin.clear(); // clear input
            cin.ignore(LONG_MAX, '\n'); // ignore any error

            viewInventory();

        } else {
            switch(choose1) {
                case 0:
                    cout << "\t\tCanceling process...";
                    Sleep(3000);

                    viewInventory();
                    break;
                
                case 1:
                    switch(stoi(choose)) {
                        case 1: // edit name of product
                            products[p_num].name = temp;
                            break;

                        case 2: // edit category of product
                            products[p_num].category = temp;
                            break;

                        case 3: // edit animal of product
                            products[p_num].animal = temp;
                            break;

                        case 4: // edit description of product
                            products[p_num].description = temp;
                            break;

                        case 5: // edit price of product
                            products[p_num].price = stod(temp);
                            break;

                        case 6: // edit stock of product
                            products[p_num].stock = stoi(temp);
                            break;

                        case 7: // edit status of product
                            if (products[p_num].status) products[p_num].status = false;
                            else products[p_num].status = true;
                            break;    
                    }

                    cout << "\t\tApplying changes...";
                    Sleep(3000);

                    viewInventory();
                    break;
                
                default:
                    invalidInput();

                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewInventory();
                    break;
            }
        }

    } else {
        invalidInput();
        viewInventory();
    }
}