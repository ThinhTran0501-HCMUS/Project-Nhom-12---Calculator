#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "Quadratic_ine.h"

using namespace std;

Quadratic_ine::Quadratic_ine() : a(0), b(0), c(0), modename("Quadratic Inequality") {}

void Quadratic_ine::set_mem() {
    string input;
    cout << "Enter a number to store in memory: ";
    cin >> input;
    mem = parse_input(input);
    cout << "Memory set to: " << mem << "\n";
}

void Quadratic_ine::print_mem() {
    cout << "Memory: " << mem << "\n";
}

void Quadratic_ine::welcome() {
    cout << "\n--- QUADRATIC INEQUALITY MODE ---\n";
    cout << "Inequality format: a*x^2 + b*x + c [>,<,>=,<=] 0\n";
    cout << "Enter coefficients one by one.\n";
    cout << "Then choose an operator: >, <, >=, or <=\n";
    cout << "Type 'setmem' or 'printmem' at any time.\n";
}

void Quadratic_ine::validate_operator(const string& input) {
    if (input == ">" || input == "<" || input == ">=" || input == "<=") {
        op = input;
    } else {
        throw invalid_argument("Invalid operator. Please enter one of: >, <, >=, <=");
    }
}

void Quadratic_ine::parse_operation(const string& str) {
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

    while (true) {
        try {
            cout << "Enter inequality operator (>, <, >=, <=): ";
            cin >> input;
            validate_operator(input);
            break;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }

    The_solver();
}

void Quadratic_ine::The_solver() {
    cout << fixed << setprecision(4);
    cout << "\nSolving: " << a << "*x^2 + " << b << "*x + " << c << " " << op << " 0\n";

    if (a == 0 && b == 0) {
        cout << "This is not a valid inequality.\n";
        return;
    }

    double delta = b * b - 4 * a * c;

    if (a == 0) {
        double root = -c / b;
        cout << "This is a linear inequality.\n";
        cout << "x " << op << " " << root << "\n";
        return;
    }

    double x1, x2;
    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        if (x1 > x2) swap(x1, x2);

        cout << "Real roots: x1 = " << x1 << ", x2 = " << x2 << "\n";

        if (a > 0) {
            if (op == ">")
                cout << "Solution: x < " << x1 << " or x > " << x2 << "\n";
            else if (op == ">=")
                cout << "Solution: x <= " << x1 << " or x >= " << x2 << "\n";
            else if (op == "<")
                cout << "Solution: " << x1 << " < x < " << x2 << "\n";
            else if (op == "<=")
                cout << "Solution: " << x1 << " <= x <= " << x2 << "\n";
        } else {
            if (op == ">")
                cout << "Solution: " << x1 << " < x < " << x2 << "\n";
            else if (op == ">=")
                cout << "Solution: " << x1 << " <= x <= " << x2 << "\n";
            else if (op == "<")
                cout << "Solution: x < " << x1 << " or x > " << x2 << "\n";
            else if (op == "<=")
                cout << "Solution: x <= " << x1 << " or x >= " << x2 << "\n";
        }
    } else if (delta == 0) {
        double x0 = -b / (2 * a);
        cout << "Double root: x = " << x0 << "\n";

        if ((op == ">=" && a > 0) || (op == "<=" && a < 0))
            cout << "Solution: x = " << x0 << "\n";
        else if ((op == ">" && a > 0) || (op == "<" && a < 0))
            cout << "No solution\n";
        else
            cout << "All x except x = " << x0 << "\n";
    } else {
        cout << "No real roots.\n";
        if ((a > 0 && (op == ">" || op == ">=")) || (a < 0 && (op == "<" || op == "<=")))
            cout << "Solution: All real x\n";
        else
            cout << "No solution\n";
    }
}