#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Calculator_mode.h"
using namespace std;

void Calculator_mode::print_name(){
    cout<<"Mode: This is the default mode."<<endl;
}

// Ham de hien thi menu
void Calculator_mode::welcome(){
    const int width = 50;
    string title = "SUPER POWER CALCULATOR";

    cout << string(width, '*') << '\n';         // bien tren
    cout << "*" << setw(width - 2) << "*" << '\n';  // khoang trang
    cout << "*";

    // trung tam data
    int padding = (width - 2 - title.length()) / 2;
    cout << string(padding, ' ') << title;
    cout << string(width - 2 - padding - title.length(), ' ') << "*\n";

    cout << "*" << setw(width - 2) << "*" << '\n';  // Empty line
    cout << string(width, '*') << '\n';         // Bottom border

    // Now list the menu options
    cout << "1. Basic Operations\n";
    cout << "2. Trigonometric Functions\n";
    cout << "3. Logarithms\n";
    cout << "4. Power and Roots\n";
    // Add more options as needed
}