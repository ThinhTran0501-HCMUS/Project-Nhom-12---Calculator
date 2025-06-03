#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include "Cubic_equa.h"

using namespace std;

Cubic_equa::Cubic_equa() : a(0), b(0), c(0), d(0), modename("Cubic Equation") {}

void Cubic_equa::set_mem() {
    string input;
    cout << "Enter a number to store in memory: ";
    cin >> input;
    mem = parse_input(input);
    cout << "Memory set to: " << mem << "\n";
}

void Cubic_equa::print_mem() {
    cout << "Memory: " << mem << "\n";
}

void Cubic_equa::welcome() {
    cout << "\n--- CUBIC EQUATION MODE ---\n";
    cout << "Equation format: a*x^3 + b*x^2 + c*x + d = 0\n";
    cout << "Enter coefficients one by one.\n";
    cout << "Type 'setmem' or 'printmem' at any time.\n";
}

void Cubic_equa::parse_operation(const string& str) {
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

    cout << "Enter coefficient d: ";
    cin >> input;
    if (input == "setmem") return set_mem();
    if (input == "printmem") return print_mem();
    d = parse_input(input);

    The_solver();
}

void Cubic_equa::The_solver() {
    cout << fixed << setprecision(4);
    if (a == 0) {
        cout << "This is not a cubic equation.\n";
        return;
    }

    double A = b / a;
    double B = c / a;
    double C = d / a;

    // Depressed cubic: t^3 + pt + q = 0
    double p = B - A * A / 3.0;
    double q = 2.0 * A * A * A / 27.0 - A * B / 3.0 + C;
    double discriminant = pow(q / 2.0, 2) + pow(p / 3.0, 3);

    double offset = A / 3.0;

    cout << "Solving: " << a << "*x^3 + " << b << "*x^2 + " << c << "*x + " << d << " = 0\n";

if (discriminant > 0) {
    double sqrt_disc = sqrt(discriminant);
    double u = cbrt(-q / 2.0 + sqrt_disc);
    double v = cbrt(-q / 2.0 - sqrt_disc);
    double root_real = u + v - offset;

    complex<double> omega1(-0.5, sqrt(3) / 2);
    complex<double> omega2(-0.5, -sqrt(3) / 2);

    complex<double> complex_root1 = (u * omega1 + v * omega2) - offset;
    complex<double> complex_root2 = (u * omega2 + v * omega1) - offset;

    cout << "One real root and two complex roots:\n";
    cout << "x1 = " << root_real << "\n";

    cout << "x2 = " << complex_root1.real();
    if (complex_root1.imag() >= 0) cout << " + " << complex_root1.imag() << "i\n";
    else cout << " - " << -complex_root1.imag() << "i\n";

    cout << "x3 = " << complex_root2.real();
    if (complex_root2.imag() >= 0) cout << " + " << complex_root2.imag() << "i\n";
    else cout << " - " << -complex_root2.imag() << "i\n";
    }else if (discriminant == 0) {
        double u = cbrt(-q / 2.0);
        double root1 = 2 * u - offset;
        double root2 = -u - offset;

        cout << "Multiple real roots:\n";
        cout << "x1 = " << root1 << "\n";
        cout << "x2 = x3 = " << root2 << "\n";
    }else {
        double r = sqrt(-pow(p / 3.0, 3));
        double phi = acos(-q / (2.0 * sqrt(-pow(p / 3.0, 3))));
        double t = 2 * cbrt(r);

        double x1 = t * cos(phi / 3.0) - offset;
        double x2 = t * cos((phi + 2 * M_PI) / 3.0) - offset;
        double x3 = t * cos((phi + 4 * M_PI) / 3.0) - offset;

        cout << "Three distinct real roots:\n";
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
        cout << "x3 = " << x3 << "\n";
    }
}
