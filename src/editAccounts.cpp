#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>

#include "petshop.h"

using namespace std;

void editAccount(int accNumber) {
    string choose, temp;
    int choose1;

    displayMenu();

    cout << endl;
    cout << "\t\t\t\t\tEditing account with an email: " << accounts[accNumber].email << endl << endl;
    cout << "\t\t\t\t\t\t\t[1] Username: " << accounts[accNumber].username << endl;
    cout << "\t\t\t\t\t\t\t[2] Password: " << accounts[accNumber].password << endl;
    cout << "\t\t\t\t\t\t\t[3]   Status: ";

    if (accounts[accNumber].status) cout << "Banned" << endl;
    else cout << "Active" << endl; 

    cout << "\t\t\t\t\t\t\t[4]  Petcoin: " << accounts[accNumber].money;

    if (accounts[accNumber].notApproved != 0) cout << "\t\tNeed approval: " << accounts[accNumber].notApproved << " Petcoin" << endl << endl;
    else cout << endl << endl;

    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << "\t\t☛ Input [option]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        menuAdmin(choose);
        editAccount(accNumber);

    } else if (checkInput(choose) == "number" && stoi(choose) <= 4 && stoi(choose) >= 1) {
        if (accounts[accNumber].notApproved == 0) {
            cout << "\t\tThere is no Petcoin in queue for approval.";
            Sleep(3000);

            editAccount(accNumber);
        }

        displayMenu();

        switch(stoi(choose)) {
            case 1:
                cout << "┃\t\t\t\t\t\t\t    𝗘 𝗗 𝗜 𝗧  𝗨 𝗦 𝗘 𝗥 𝗡 𝗔 𝗠 𝗘  \t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld username: " << accounts[accNumber].username << endl;
                cout << "\t\t\t\t\t\t  Enter new username: ";

                cin >> temp;
                break;

            case 2:
                cout << "┃\t\t\t\t\t\t\t    𝗘 𝗗 𝗜 𝗧  𝗣 𝗔 𝗦 𝗦 𝗪 𝗢 𝗥 𝗗  \t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;

                cout << "\t\t\t\t\t\t\tOld password: " << accounts[accNumber].password << endl;
                cout << "\t\t\t\t\t\t  Enter new password: ";

                cin >> temp;
                break;

            case 3:
                cout << "┃\t\t\t\t\t\t\t\t𝗘 𝗗 𝗜 𝗧  𝗦 𝗧 𝗔 𝗧 𝗨 𝗦\t\t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;
                
                if (accounts[accNumber].status) cout << "\t\t\t\t\t\t\tStatus: Banned ⟶ Active  \t\t\t\t" << endl;
                else cout << "\t\t\t\t\t\t\tStatus: Active ⟶ Banned  \t\t\t\t" << endl;

                break;

            case 4:
                
                cout << "┃\t\t\t\t\t\t\t    𝗡 𝗘 𝗘 𝗗  𝗔 𝗣 𝗣 𝗥 𝗢 𝗩 𝗔 𝗟  \t\t\t\t\t\t┃" << endl;
                cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl << endl;
                cout << "\t\t\t\t\t\t\t\tPetcoin: " << accounts[accNumber].notApproved << endl;

                break;

            default:
                invalidInput();
                
                cout << "\t\tCanceling process...";
                Sleep(2000);

                editAccount(accNumber);
                break;
        }

        cout << endl;
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        
        if (stoi(choose) == 4) cout << "┃\t\t\t\t[1] Approved\t\t\t\t┃\t\t\t\t[0] Not Approved\t\t\t\t┃" << endl;
        else cout << "┃\t\t\t\t[1] Save\t\t\t\t┃\t\t\t\t[0] Cancel\t\t\t\t┃" << endl;

        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

        cout << "\t\t☛ Input option: ";
        cin >> choose1;

        cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

        //check if string is inputted in an int variable
        if (cin.fail()) {
            invalidInput();
            
            cout << "\t\tCanceling process...";
            Sleep(2000);

            cin.clear();//clear input
            cin.ignore(LONG_MAX, '\n');//ignore any error

            viewAccounts();

        } else {
            switch(choose1) {
                case 0:
                    if (stoi(choose) == 4) accounts[accNumber].notApproved = 0;
                    else {
                        cout << "\t\tCanceling process...";
                        Sleep(3000);

                        viewAccounts();
                    }
                    break;
                
                case 1:
                    switch(stoi(choose)) {
                        case 1: // edit user's username
                            accounts[accNumber].username = temp;
                            break;

                        case 2: // edit user's password
                            accounts[accNumber].password = temp;
                            break;

                        case 3: // edit user's status
                            if (accounts[accNumber].status) accounts[accNumber].status = false;
                            else accounts[accNumber].status = true;
                            break;

                        case 4: // edit user's status
                            accounts[accNumber].money += accounts[accNumber].notApproved;
                            accounts[accNumber].notApproved = 0;
                            break;
                    }

                    cout << "\t\tApplying changes...";
                    Sleep(3000);

                    viewAccounts();
                    break;
                
                default:
                    invalidInput();

                    cout << "\t\tCanceling process...";
                    Sleep(2000);

                    viewAccounts();
                    break;
            }
        }

    } else {
        invalidInput();
        editAccount(accNumber);
    }
}