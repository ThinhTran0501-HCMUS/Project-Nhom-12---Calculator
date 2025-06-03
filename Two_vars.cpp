#include "Two_vars.h"
#include <limits>
#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>

Two_vars::Two_vars()
    : a1(0), b1(0), c1(0), a2(0), b2(0), c2(0), modeName("Two-variable System") {}

double Two_vars::parse_input(const string& str) {
    return Equation_solve::parse_input(str);
}

void Two_vars::welcome() {
    cout << "\n--- TWO-VARIABLE SYSTEM OF EQUATIONS MODE ---\n";
    cout << "Equation format: a1*x + b1*y = c1\n";
    cout << "                 a2*x + b2*y = c2\n";
    cout << "You can enter coefficients one by one.\n";
    cout << "Type 'setmem' to set memory value.\n";
    cout << "Type 'printmem' to view memory.\n";
}

void Two_vars::print_name() {
    cout << "Mode: " << modeName << "\n";
}

void Two_vars::set_mem() {
    string input;
    cout << "Enter a number to store in memory: ";
    cin >> input;
    mem = parse_input(input);
    cout << "Memory set to: " << mem << "\n";
}

void Two_vars::print_mem() {
    cout << "Memory: " << mem << "\n";
}

void Two_vars::parse_operation(const string& str) {
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

    The_solver();
}

void Two_vars::The_solver() {
    float D = a1 * b2 - a2 * b1;
    float Dx = c1 * b2 - c2 * b1;
    float Dy = a1 * c2 - a2 * c1;

    if (D == 0) {
        if (Dx == 0 && Dy == 0) {
            cout << "Infinite solutions.\n";
        } else {
            cout << "No solution.\n";
        }
    } else {
        x = Dx / D;
        y = Dy / D;
        cout << fixed << setprecision(4);
        cout << "Solution: x = " << x << ", y = " << y << "\n";
    }
}