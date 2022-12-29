#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>

#include "petshop.h"

using namespace std;

void title();

void loading() {
    
    SetConsoleOutputCP(CP_UTF8); // line of code to print unicode/special/emoji characters

    // Display loading animation
    vector<string> load_top = { "█", "░░▄▀", "▄▄▄▄", "▀▄░", "▀▄░" };

    vector<string> load_bottom = { "█", "▄▀░░", "░░", "░░▀▄", "░░▀▄" };

    vector<string> numbers_top = { "█▀█", "▄█", "▀█", "", "█░█", "█▀", "█▄▄", "▀▀█", "", "█▀█" };

    vector<string> numbers_bottom = { "█▄█", "░█", "█▄", "", "▀▀█", "▄█", "█▄█", "░░█", "", "▀▀█" };

    int count = 0;
    
    for (int i = 0; i <= 100; i++) {
        // Check if the number contains 3 or 8
        if (to_string(i).find('3') != string::npos || to_string(i).find('8') != string::npos) continue; // Skip this iteration
        
        title();

        string num = "";

        if (i != 0) {
            // Build the number using the digits in the vector
            for (int j = i; j > 0; j /= 10) {
                num = numbers_top[j % 10] + " " + num;
            }

        } else num = numbers_top[0] + " " + num;

        cout << "\t\t\t\t█░░ █▀█ ▄▀█ █▀▄ █ █▄░█ █▀▀    █▀ █▄█ █▀ ▀█▀ █▀▀ █▀▄▀█\t" << load_top[count % 4] << "\t" << num << " " << "▀░▄▀" << endl;

        num = "";

        if (i != 0) {
            for (int j = i; j > 0; j /= 10) {
                num = numbers_bottom[j % 10] + " " + num;
            }

        } else num = numbers_bottom[0] + " " + num;

        cout << "\t\t\t\t█▄▄ █▄█ █▀█ █▄▀ █ █░▀█ █▄█    ▄█ ░█░ ▄█ ░█░ ██▄ █░▀░█\t" << load_bottom[count % 4] << "\t" << num << " " << "▄▀░▄" << endl;

        count++;

        this_thread::sleep_for(chrono::milliseconds(100));
    }

    Sleep(2000);

    title();
    
    cout << "                             █▀█ █▀█ █▀▀ █▀ █▀   █▀▀ █▄░█ ▀█▀ █▀▀ █▀█    ▀█▀ █▀█   █▀▀ █▀█ █▄░█ ▀█▀ █ █▄░█ █░█ █▀▀ ░" << endl;
    cout << "                             █▀▀ █▀▄ ██▄ ▄█ ▄█   ██▄ █░▀█ ░█░ ██▄ █▀▄    ░█░ █▄█   █▄▄ █▄█ █░▀█ ░█░ █ █░▀█ █▄█ ██▄ ▄" << endl;

    cin.get(); // Wait for user to press enter

    Sleep(2000);
}

void title() {
    system("cls");

    cout << endl << endl;
    cout << "                              ░██╗░░░░░░░██╗███████╗██╗░░░░░░█████╗░░█████╗░███╗░░░███╗███████╗   ████████╗░█████╗░" << endl;
    cout << "                              ░██║░░██╗░░██║██╔════╝██║░░░░░██╔══██╗██╔══██╗████╗░████║██╔════╝   ╚══██╔══╝██╔══██╗" << endl;
    cout << "                              ░╚██╗████╗██╔╝█████╗░░██║░░░░░██║░░╚═╝██║░░██║██╔████╔██║█████╗░░   ░░░██║░░░██║░░██║" << endl;
    cout << "                              ░░████╔═████║░██╔══╝░░██║░░░░░██║░░██╗██║░░██║██║╚██╔╝██║██╔══╝░░   ░░░██║░░░██║░░██║" << endl;
    cout << "                              ░░╚██╔╝░╚██╔╝░███████╗███████╗╚█████╔╝╚█████╔╝██║░╚═╝░██║███████╗   ░░░██║░░░╚█████╔╝" << endl;
    cout << "                              ░░░╚═╝░░░╚═╝░░╚══════╝╚══════╝░╚════╝░░╚════╝░╚═╝░░░░░╚═╝╚══════╝   ░░░╚═╝░░░░╚════╝░" << endl << endl;
            
    cout << "                                ██████╗░███████╗████████╗███████╗██╗░░██╗██████╗░██████╗░███████╗░██████╗░██████╗" << endl;
    cout << "                                ██╔══██╗██╔════╝╚══██╔══╝██╔════╝╚██╗██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝" << endl;
    cout << "                                ██████╔╝█████╗░░░░░██║░░░█████╗░░░╚███╔╝░██████╔╝██████╔╝█████╗░░╚█████╗░╚█████╗░" << endl;
    cout << "                                ██╔═══╝░██╔══╝░░░░░██║░░░██╔══╝░░░██╔██╗░██╔═══╝░██╔══██╗██╔══╝░░░╚═══██╗░╚═══██╗" << endl;
    cout << "                                ██║░░░░░███████╗░░░██║░░░███████╗██╔╝╚██╗██║░░░░░██║░░██║███████╗██████╔╝██████╔╝" << endl;
    cout << "                                ╚═╝░░░░░╚══════╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚═════╝░╚═════╝░" << endl << endl << endl;
}    