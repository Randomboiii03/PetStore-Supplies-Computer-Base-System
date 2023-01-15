#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <type_traits>

#include "petshop.h"

using namespace std;

template <typename T>
typename enable_if<is_same<T, Product>::value, vector<T>>::type
search(const vector<T>& items, const string& SearchTerm);

void searchProducts() {
    string searchTerm, choose;

    displayMenu();

    cin.clear(); // clear input
    cin.ignore(LONG_MAX, '\n'); // ignore any error
    
    cout << "\t\t🔎 Enter a search term:  ";
    getline(cin, searchTerm);

    vector<Product> results = search<Product>(products, searchTerm);

    cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
    cout << "┃\t\t\tProduct Name\t\t\t┃\t\tCategory\t\t┃\t  Animal      \t┃\t  Price      \t┃" << endl;
    
    if (!results.empty()) {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;
       
        // displaying search results
        for (int i = 0; i < results.size(); i++) {
            for (int j = 0; j < products.size(); j++) {
                if (results[i].name == products[j].name && results[i].status) {
                    cout << "┃\t\t[" << j << "] " << results[i].name << "\t\t";

                    if (results[i].name.length() <= 10) cout << "\t\t";
                    else if (results[i].name.length() <= 19 && j < 10) cout << "\t";
                    else if (results[i].name.length() <= 18 && j >= 10) cout << "\t";

                    cout << "┃\t\t" << results[i].category;

                    if (results[i].category == "Food") cout << "\t";

                    cout << "\t\t┃\t   " << results[i].animal << "     \t┃\t  ₱ " << products[i].price << "      \t┃" << endl;

                    break;
                }
            }
        }
        
        cout << "┃\t\t\t\t\t\t\t┃\t\t\t\t\t┃\t\t\t┃\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    } else {
        cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\tNo result for: " << searchTerm << "\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┃\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    }

    cout << "\t\t☛ Input [option]: ";
    cin >> choose;

    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

    if (checkInput(choose) == "alpha" && choose.length() == 1) {
        transform(choose.begin(), choose.end(), choose.begin(), ::tolower);

        if (loginEmail == "admin") menuAdmin(choose);
        else menuCustomer(choose);

        searchProducts();

    } else if (checkInput(choose) == "number" && products.size() > stoi(choose) && stoi(choose) >= 0) {
        if (loginEmail == "admin") editItem(stoi(choose));
        else if (products[stoi(choose)].status) viewItem(stoi(choose));

        invalidInput();
        searchProducts();

    } else {
        invalidInput();
        searchProducts();
    }       
}

template <typename T>
typename enable_if<is_same<T, Product>::value, vector<T>>::type
search(const vector<T>& items, const string& SearchTerm) {
    vector<T> results;

    // convert the search term to lower case
    string lowerCaseSearchTerm = SearchTerm;
    transform(lowerCaseSearchTerm.begin(), lowerCaseSearchTerm.end(), lowerCaseSearchTerm.begin(), ::tolower);
        
    for (const auto& product : items) {

        // convert the products name, category, animals, and description to lower case
        string lowerCaseName = product.name;
        transform(lowerCaseName.begin(), lowerCaseName.end(), lowerCaseName.begin(), ::tolower);
        string lowerCaseCategory = product.category;
        transform(lowerCaseCategory.begin(), lowerCaseCategory.end(), lowerCaseCategory.begin(), ::tolower);
        string lowerCaseAnimal = product.animal;
        transform(lowerCaseAnimal.begin(), lowerCaseAnimal.end(), lowerCaseAnimal.begin(), ::tolower);
        string lowerCaseDescription = product.description;
        transform(lowerCaseDescription.begin(), lowerCaseDescription.end(), lowerCaseDescription.begin(), ::tolower);

        // search the lower case version of the product  name, category,animals, and description
        if (contains(lowerCaseName, lowerCaseSearchTerm) ||
            contains(lowerCaseCategory, lowerCaseSearchTerm) ||
            contains(lowerCaseAnimal, lowerCaseSearchTerm) ||
            contains(lowerCaseDescription, lowerCaseSearchTerm)) {
            results.push_back(product);
        }
    }

    return results;
}
