#include "Three_vars.h"
#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

Three_vars::Three_vars():a1(0),b1(0),c1(0),d1(0),a2(0),b2(0),c2(0),d2(0),a3(0),b3(0),c3(0),d3(0),modename("Three-variable system"){}

void Three_vars::welcome() {
    cout << "\n--- THREE-VARIABLE SYSTEM OF EQUATIONS MODE ---\n";
    cout << "Equation format: a1*x + b1*y + c1*z = d1\n";
    cout << "                 a2*x + b2*y + c2*z = d2\n";
    cout << "                 a3*x + b3*y + c3*z = d3\n";
    cout << "You can enter coefficients one by one.\n";
    cout << "Type 'setmem' to set memory value.\n";
    cout << "Type 'printmem' to view memory.\n";
}

void Three_vars::The_solver() {
    // Cramer's Rule
    float D, Dx, Dy, Dz;

    D = a1*(b2*c3 - b3*c2) - b1*(a2*c3 - a3*c2) + c1*(a2*b3 - a3*b2);
    Dx = d1*(b2*c3 - b3*c2) - b1*(d2*c3 - d3*c2) + c1*(d2*b3 - d3*b2);
    Dy = a1*(d2*c3 - d3*c2) - d1*(a2*c3 - a3*c2) + c1*(a2*d3 - a3*d2);
    Dz = a1*(b2*d3 - b3*d2) - b1*(a2*d3 - a3*d2) + d1*(a2*b3 - a3*b2);

    if (D == 0) {
        if (Dx == 0 && Dy == 0 && Dz == 0)
            cout << "Infinite solutions.\n";
        else
            cout << "No solution.\n";
    } else {
        x = Dx / D;
        y = Dy / D;
        z = Dz / D;
        cout << "Solution:\n";
        cout << "x = " << x << "\n";
        cout << "y = " << y << "\n";
        cout << "z = " << z << "\n";
    }
}

void Three_vars::parse_operation(const string &str){
    string input;
    cout << "Enter coefficient a1: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    a1 = parse_input(input);

    cout << "Enter coefficient b1: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    b1 = parse_input(input);

    cout << "Enter coefficient c1: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    c1 = parse_input(input);

    cout << "Enter coefficient d1: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    d1 = parse_input(input);

    cout << "Enter coefficient a2: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    a2 = parse_input(input);

    cout << "Enter coefficient b2: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    b2 = parse_input(input);

    cout << "Enter coefficient c2: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    c2 = parse_input(input);

    cout << "Enter coefficient d2: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    d2 = parse_input(input);

    cout << "Enter coefficient a3: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    a3 = parse_input(input);

    cout << "Enter coefficient b3: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    b3 = parse_input(input);

    cout << "Enter coefficient c3: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    c3 = parse_input(input);

    cout << "Enter coefficient d3: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    d3 = parse_input(input);

    The_solver();
}