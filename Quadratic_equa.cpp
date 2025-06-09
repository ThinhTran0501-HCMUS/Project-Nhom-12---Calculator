#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <complex>
#include "Equation_solve.h"
#include "Quadratic_equa.h"
using namespace std;

Quadratic_equa::Quadratic_equa():a(0),b(0),c(0),modename("Two-degree equation"){}

void Quadratic_equa::print_mem() {
    cout << "Memory: " << mem << "\n";
}

void Quadratic_equa::set_mem() {
    string input;
    cout << "Enter a number to store in memory: ";
    cin >> input;
    mem = parse_input(input);
    cout << "Memory set to: " << mem << "\n";
}

void Quadratic_equa::welcome(){
    cout << "\n--- TWO-DEGREE EQUATION MODE ---\n";
    cout << "Equation format: a*x^2 + b*x + c = 0\n";
    cout << "You can enter coefficients one by one.\n";
    cout << "Type 'setmem' to set memory value.\n";
    cout << "Type 'printmem' to view memory.\n";
}

void Quadratic_equa::parse_operation(const string& str){
        string input;

        cout << "Enter coefficient a: ";
        cin >> input;
        if (input == "setmem") return set_mem();
        if (input == "printmem") return print_mem();
        a = parse_input(input);

        cout << "Enter coefficient b: ";
        cin >> input;
        if (input == "setmem") return set_mem();
        if (input == "printmem") return print_mem();
        b = parse_input(input);

        cout << "Enter coefficient c: ";
        cin >> input;
        if (input == "setmem") return set_mem();
        if (input == "printmem") return print_mem();
        c = parse_input(input);

        The_solver();
    }

void Quadratic_equa::The_solver(){
        cout << fixed << setprecision(4);
        if (a == 0 && b == 0 && c == 0) {
            cout << "The equation has infinite roots.\n";
        } else if (a == 0 && b == 0 && c != 0) {
            cout << "The equation has no roots.\n";
        } else if (a == 0 && b != 0) {
            x1 = x2 = -c / b;
            cout << "This is a linear equation.\n";
            cout << "x = " << x1 << "\n";
        } else {
            double delta = b * b - 4 * a * c;
            if (delta == 0) {
                x1 = x2 = -b / (2 * a);
                cout << "The equation has a double root: x = " << x1 << "\n";
            } else if (delta > 0) {
                x1 = (-b + sqrt(delta)) / (2 * a);
                x2 = (-b - sqrt(delta)) / (2 * a);
                cout << "The equation has two real roots:\n";
                cout << "x1 = " << x1 << ", x2 = " << x2 << "\n";
            } else {
                double realPart = -b / (2 * a);
                double imagPart = sqrt(-delta) / (2 * a);
                cout << "The equation has two imaginary roots:\n";
                cout << "x1 = " << realPart << " + " << imagPart << "i\n";
                cout << "x2 = " << realPart << " - " << imagPart << "i\n";
            }
        }
    }