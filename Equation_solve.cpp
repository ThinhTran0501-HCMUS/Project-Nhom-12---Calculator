#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Equation_solve.h"
using namespace std;
Equation_solve::Equation_solve()
: choice(1), mem(0.0),
  x(0.0), y(0.0), z(0.0), x1(0.0), x2(0.0), x3(0.0),
  modeName("Equation solver"){}

double Equation_solve::parse_input(string const &str){
        // Lowercase input for easier comparison
    string in;
    for (char c : str)
        in += tolower(c);

    // Named constants
    if (in == "pi") return 3.141592653589793;
    if (in == "e")  return 2.718281828459045;

    // Word to number map
    if (in == "zero")  return 0;
    if (in == "one")   return 1;
    if (in == "two")   return 2;
    if (in == "three") return 3;
    if (in == "four")  return 4;
    if (in == "five")  return 5;
    if (in == "six")   return 6;
    if (in == "seven") return 7;
    if (in == "eight") return 8;
    if (in == "nine")  return 9;

    // Special keywords
    if (in == "x") return x;  // assuming `result` is defined in class
    if (in == "mem")    return mem;
    if (in=="y") return y;     // assuming `mem` is defined in class
    if (in=="z") return z;
    if (in=="x1") return x1;
    if (in=="x2") return x2;
    if (in=="x3") return x3;

    // Try to parse number
    try {
        return stod(str);
    } catch (...) {
        cerr << "Invalid input: " << str << ". Defaulting to 0.\n";
        return 0.0;
    }
}

void Equation_solve:: welcome(){
    cout<<"\n EQUATION SOLVER\n";
    // Cac lua chon
    cout << "Please select a mode:\n\n";

    cout << "  1. Quadratic Equation\n";
    cout << "  2. Cubic Equation\n";
    cout << "  3. Quadratic Inequality \n\n";

    cout << "  4. Cubic Inequality\n";
    cout << "  5. Two-Variables System.\n";
    cout << "  6. Three-Variables System.\n\n";

    cout << "  7. Exit\n";
}
void Equation_solve:: parse_operation(string const &str){
    cout<<"Under construction\n";
}
void Equation_solve:: print_name(){
    cout<<"Mode: "<<modeName<<"\n";
}
void Equation_solve::set_choice(int choice){
this->choice=choice;
}
int Equation_solve::get_choice(){
return choice;
}