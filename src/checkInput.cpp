#include <iostream>
#include <string>

#include "petshop.h"

using namespace std;

string checkInput(string choose) {
    bool only_alpha = false, only_digit = false;

    for (char c : choose) {
        if (isalpha(c)) only_alpha = true;  // the character is not alphabet
        else if (isdigit(c)) only_digit = true;  // the character is not a digit
    }

    if (only_alpha && !only_digit) return "alpha";
    else if (only_digit && !only_alpha) return "number";

    return "invalid";
}