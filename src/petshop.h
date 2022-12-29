#ifndef PETSHOP_H
#define PETSHOP_H

#include <string>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

struct Account {
    string username;
    string email;
    string password;
    double money;
    double notApproved;
    bool status;
};

struct Product {
    string name;
    string category;
    string animal;
    string description;
    double price;
    int stock;
    bool status;
};

struct Cart {
    string email;
    int product;
    int quantity;
    bool status;
};

struct Checkout {
    string email;
    int product;
    int quantity;
    string date;
};

struct Receipt {
    string email;
    int product;
    int quantity;
    string date;
};

extern vector<Account> accounts;
extern vector<Product> products;
extern vector<Cart> carts;
extern vector<Checkout> checkouts;
extern vector<Receipt> receipts;

extern bool loginStatus;
extern string loginEmail;

void loading();
void displayMenu();
void login();
void registration();
void accountProfile();
void menuAdmin(string choose);
void homeAdmin();
void searchAdmin();
void searchAccounts();
void searchProducts();
void viewAccounts();
void editAccount(int accNumber);
void viewInventory();
void addItem();
void editItem(int p_num);
void viewCheckouts();
void menuCustomer(string choose);
void homeCustomer();
void foods();
void equipments();
void medicine();
void viewItem(int p_num);
void cart();
void menuCart(int p_num);
double checkoutList();
void checkout();
void dedactProduct();
void invalidInput();
bool checkAccount(string accountType);
string checkInput(string choose);
int getRandomNumber(const vector<Product>& vec);
string getCurrentTime();
bool contains(const string& str, const string& searchProd);

#endif // PETSHOP_H