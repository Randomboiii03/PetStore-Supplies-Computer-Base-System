#include <iostream>
#include <string>

#include "petshop.h"

using namespace std;

bool contains(const string& str, const string& searchTerm) {
    return str.find(searchTerm) != string::npos; // check if searchTerm is in any searchable lists
}