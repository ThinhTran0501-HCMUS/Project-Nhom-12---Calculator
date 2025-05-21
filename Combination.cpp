#include "Combination.h"
#include <iostream>

using namespace std;

Combination::Combination() : ans(0), preans(0) {}
Combination::~Combination(){}
int Combination::factorial(int n) { 
    int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

double Combination::parseInput(string& input) { 
    if (input == "mem") return mem;
    if (input == "result") return result;
    double value;
    cin>>value;
    return value;
}

void Combination::welcome() {
    cout << "Welcome to Combination Mode!" << endl;
}

void Combination::parseOperation(string& op) {
    if (op == "print_mem") printMem();
    else if (op == "set_mem") setMem();
    else cout << "Unknown operation.\n";
}

void Combination::combi_cal(int n, int r) {
    preans = ans;
    ans = factorial(n) / (factorial(r) * factorial(n - r));
    result = ans;
    cout << "C(" << n << ", " << r << ") = " << ans << endl;
}

void Combination::arrangement(int n, int r) {
    preans = ans;
    ans = factorial(n) / factorial(n - r);
    result = ans;
    cout << "A(" << n << ", " << r << ") = " << ans << endl;
}

void Combination::permutation(int n) {
    preans = ans;
    ans = factorial(n);
    result = ans;
    cout << "P(" << n << ") = " << ans << endl;
}

void Combination::setMem() {
    mem = result;
    cout << "Memory set to: " << mem << endl;
}

void Combination::printMem() {
    cout << "Memory value: " << mem << endl;
}
