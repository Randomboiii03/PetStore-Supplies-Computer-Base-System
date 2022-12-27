#include <iostream>
#include <string>
#include <windows.h>

#include "petshop.h"

using namespace std;

bool loginStatus = false;
string loginEmail = "";

vector<Account> accounts;
vector<Product> products;
vector<Cart> carts;
vector<Checkout> checkouts;
vector<Receipt> receipts;

int main() {

    // Get the window handle of the console window
    HWND consoleWindow = GetConsoleWindow();
    // Maximize the window
    ShowWindow(consoleWindow, SW_MAXIMIZE);

    // admin's account
    accounts.push_back({"admin", "admin", "admin", 0, 0, false});

    // customer's account
    accounts.push_back({"gabrielle", "gabrielleramos@gmail.com", "gab", 10000, 0, false});

    // add more account for test and presentation here

    // products for "cat" to the vector
    products.push_back({"Maxime (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 90, 30, true});
    products.push_back({"Whiskas (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 155, 30, false});
    products.push_back({"Cuties (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 130, 30, true});
    products.push_back({"Smartheart (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 165, 30, true});
    products.push_back({"Kitcat (1 kilo)", "Food", "Cat", "5-6 weeks old higher", 52, 30, true});
    products.push_back({"Whiskas (400 g)", "Food", "Cat", "1 Years above", 99, 30, true});
    products.push_back({"Goodest (85 g)", "Food", "Cat", "6 Months above", 28, 30, true});
    products.push_back({"Aozi (430 g)", "Food", "Cat", "7 Months above", 82, 30, true});
    products.push_back({"Lc Vit Plus (120ml)", "Medicine", "Cat", "12 weeks higher", 150, 30, true});
    products.push_back({"Pneumex (60ml)", "Medicine", "Cat", "3 months", 167, 30, true});
    products.push_back({"Advocate (4 kg)", "Medicine", "Cat", "9 weeks higher", 499, 30, true});
    products.push_back({"Wormeze (8 oz)", "Medicine", "Cat", "6 months higher", 719, 30, true});
    products.push_back({"Drontal (18.2 mg)", "Medicine", "Cat", "1 month higher", 313, 30, true});
    products.push_back({"Capstar (57 mg)", "Medicine", "Cat", "4 weeks higher", 475, 30, true});
    products.push_back({"Capaction (11.4 mg)", "Medicine", "Cat", "4 weeks higher", 137, 30, true});
    products.push_back({"Flea Guard (2.5 ml)", "Medicine", "Cat", "8 weeks higher", 125, 30, true});
    products.push_back({"Litter Box", "Equipment", "Cat", "Splash proof cat litter box", 260, 30, true});
    products.push_back({"Bed", "Equipment", "Cat", "Cat Bed House", 120, 30, true});
    products.push_back({"Scratching Posts", "Equipment", "Cat", "Cat Scratch Post ", 66, 30, true});
    products.push_back({"Toy Bell", "Equipment", "Cat", "Wiggly Ball Cat Bells", 57, 30, true});
    products.push_back({"Food/Water Bowl", "Equipment", "Cat", "2 in 1 Cat Bowl", 119, 30, true});
    products.push_back({"Collar ", "Equipment", "Cat", "Adjustable w/ bell", 48, 30, true});
    products.push_back({"Cage", "Equipment", "Cat", "Collapsible cage", 399, 30, true});
    products.push_back({"Litter Sand (10 L)", "Equipment", "Cat", "Lavender scent", 250, 30, true});

   // products for "dog" to the vector
    products.push_back({"Nutrichunks (500 g)", "Food", "Dog", "12 months old above", 250, 30, true});
    products.push_back({"Vitalamb (1kg)", "Food", "Dog", "15 months old above", 102, 30, true});
    products.push_back({"Pedigree (1kg)", "Food", "Dog", "4 weeks old above", 146, 30, true});
    products.push_back({"Top Breed (1kg)", "Food", "Dog", "4 months old above", 99, 30, true});
    products.push_back({"Royal Canin (500g)", "Food", "Dog", "ten months old above", 179, 30, true});
    products.push_back({"Pedigree Pouch (30g)", "Food", "Dog", "3 weeks old above", 32, 30, true});
    products.push_back({"Jerhigh Pouch (120g)", "Food", "Dog", "2 months old above", 50, 30, true});
    products.push_back({"SmartHeart Pouch (80g)", "Food", "Dog", "2 months old above", 39, 30, true});
    products.push_back({"Himalaya (100ml)", "Medicine", "Dog", "treats for liver, kidney, digestive, etc.", 265, 30, true});
    products.push_back({"Multivitamins (120 ml)", "Medicine", "Dog", "12 weeks above", 118, 30, true});
    products.push_back({"Nematocide (15ml)", "Medicine", "Dog", "against roundworms & hookworms", 115, 30, true});
    products.push_back({"Doxycycline (60 ml)", "Medicine", "Dog", "tetracycline antibiotic for anaplasma, heartworm & periodontal disease", 107, 30, true});
    products.push_back({"Nexgard (260 g)", "Medicine", "Dog", "protection for fleas, ticks & mites", 419, 30, true});
    products.push_back({"Wormgard (150 mg)", "Medicine", "Dog", "for control of all gastrointestinal worms", 165, 30, true});
    products.push_back({"Simparica trio (120 mg)", "Medicine", "Dog", "against naturally occurring flea & tick infestations", 495, 30, true});
    products.push_back({"Bravecto (98 mg)", "Medicine", "Dog", "for parasites", 394, 30, true});
    products.push_back({"Dog bowl", "Equipment", "Dog", "for placement of dog food & water", 75, 30, true});
    products.push_back({"Dog bed", "Equipment", "Dog", "for comfortable god sleep", 181, 30, true});
    products.push_back({"Dog backpack ", "Equipment", "Dog", "for owner's dog carrier", 189, 30, true});
    products.push_back({"Dog collar", "Equipment", "Dog", "for dog's restraint & protection", 98, 30, true});
    products.push_back({"Clothes", "Equipment", "Dog", "for dog's fashion & cold protection", 125, 30, true});
    products.push_back({"Diaper", "Equipment", "Dog", "for dog's urinary incontinence", 65, 30, true});
    products.push_back({"Muzzles", "Equipment", "Dog", "preventive equipment for dog's violence", 89, 30, true});
    products.push_back({"Dog crate", "Equipment", "Dog", "for dog's confinement", 120, 30, true});

    // products for "fish" to the vector
    products.push_back({"Fish flakes (20 g)", "Food", "Fish", "all ages of fish", 160, 30, true});
    products.push_back({"Fish pellets (50 g)", "Food", "Fish", "all ages of fish", 67, 30, true});
    products.push_back({"Pimafix (16 oz)", "Medicine", "Fish", "for fungal infections", 370, 30, true});
    products.push_back({"Aqua Guard (1L)", "Medicine", "Fish", "purifier for high water savings", 93, 30, true});
    products.push_back({"API Melafix (16 oz)", "Medicine", "Fish", "all- natural antibacterial treatment for fish infections", 350, 30, true});
    products.push_back({"Paracidol-Fw (100ml)", "Medicine", "Fish", "for external & internal parasitic infection", 124, 30, true});
    products.push_back({"Air pump", "Equipment", "Fish", "promotes gas exchange at water surface", 135, 30, true});
    products.push_back({"Aquarium (5 gal)", "Equipment", "Fish", "artificial habitats for fish", 290, 30, true});
    products.push_back({"Aquarium heater (50w)", "Equipment", "Fish", "keeps aquarium temperature warm", 199, 30, true});

    // products for "bird" to the vector
    products.push_back({"Bird seed mix (1k)", "Food", "Bird", "for all ages of bird", 30, 30, true});
    products.push_back({"African mix (1k)", "Food", "Bird", "for all ages of bird", 75, 30, true});
    products.push_back({"Parakeet (500 g)", "Food", "Bird", "for all ages of bird", 245, 30, true});
    products.push_back({"Premium mix (1k)", "Food", "Bird", "for all ages of bird", 68, 30, true});
    products.push_back({"Mynah bird food (1kg)", "Food", "Bird", "for all ages of bird", 195, 30, true});
    products.push_back({"Baytril (12,5 ml)", "Medicine", "Bird", "for bacterial infections", 240, 30, true});
    products.push_back({"Amtyl (500 g)", "Medicine", "Bird", "for prevention of CRD & fowl pox", 150, 30, true});
    products.push_back({"Enrofloxacin (20 ml)", "Medicine", "Bird", "for bacterial infections", 279, 30, true});
    products.push_back({"Pikoy BACTI Bird (10 ml)", "Medicine", "Bird", "for bird's systemic & bacterial infections", 148, 30, true});
    products.push_back({"Aviator Harness & Leash", "Equipment", "Bird", "for safely taking bird outside", 143, 30, true});
    products.push_back({"Bird cage", "Equipment", "Bird", "protects bird from getting out", 500, 30, true});
    products.push_back({"Bird feeder", "Equipment", "Bird", "equipment for placing bird food", 113, 30, true});

    homeCustomer();
}