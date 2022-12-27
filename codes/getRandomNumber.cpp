#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "petshop.h"

using namespace std;

int getRandomNumber(const vector<Product>& vec) {
    return rand() % vec.size(); // generate random number base on count of product
}