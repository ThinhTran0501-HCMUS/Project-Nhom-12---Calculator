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
    cout << "*" << setw(width - 1) << "*" << '\n';  // khoang trang
    // cout << "*";

    // trung tam data
    int padding = (width - 2 - title.length()) / 2;
    cout <<"*"<< string(padding, ' ') << title;
    cout << string(width - 2 - padding - title.length(), ' ') << "*\n";

    cout << "*" << setw(width - 1) << "*" << '\n';  // khoang trang
    cout << string(width, '*') << '\n';         // bien duoi
    cout << '\n';

    // Cac lua chon
    cout << "Please select a mode:\n\n";

    cout << "  1. Basic Operations\n";
    cout << "  2. Combination\n";
    cout << "  3. Unit Converter\n\n";

    cout << "  4. Polynomial Simplification\n";
    cout << "  5. Base-N Converter\n";
    cout << "  6. Matrix Calculator\n\n";

    cout << "  7. Equation Solver\n\n";

    cout << "Please enter your choice: ";
}