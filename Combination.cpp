#include "Combination.h"
#include <iostream>
#include <string.h>

using namespace std;

Combination::Combination() : ans(0), preans(0),mem(0),modeName("Combination"){}
int Combination::factorial(int n) {
    if(n==0||n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

double Combination::parse_input(string const &str) { 
    // Lowercase input for easier comparison
    string in;
    for (char c : str)
        in += tolower(c);

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
        // Cố gắng chuyển thành số
     if (in == "ans"||in=="result")
    {
        return ans;
    }
    else if (in == "mem")
    {
        return mem;
    }
    else if(in == "preans")
    {
        return preans;
    } 
    // Try to parse number
    try {
        return stod(str);
    } catch (...) {
        cerr << "Invalid input: " << str << ". Defaulting to 0.\n";
        return 0.0;
    }
}  

void Combination::welcome() {
    cout << "         COMBINATION MODE\n"
    <<"         Enter your input\n"
    <<"--------------------------------------\n"
    <<"   combi    arran     permu\n"
    <<"  setmem   printmem   exit\n"
    <<"--------------------------------------\n";  
}

void Combination::parse_operation(const string& input) {
    string in;
    for (char c : input)
        in += tolower(c);

    if (in == "com"||in=="comb"||in=="combi"||in=="combin"
    ||in=="combina"||in=="combination"){
        combi_cal();
    }
    else if (in == "arr"||in=="arra"||in=="arran"||in=="arrang"
    ||in=="arrange"||in=="arrangement"){
        arrangement();
    }
    else if (in=="per"||in=="perm"||in=="permu"||in=="permut"
    ||in=="permuta"||in=="permutation"){
        permutation();
    }
    else {
        cerr << "Invalid operator\n";
    }
}

void Combination::combi_cal() {
    string n_str, r_str;
    cout << "Enter total elements: ";
    cin >> n_str;
    cout << "Enter subset size: ";
    cin >> r_str;

    int n_val = static_cast<int>(parse_input(n_str));
    int r_val = static_cast<int>(parse_input(r_str));

    // Validation
    if (n_val < 0 || r_val < 0) {
        cerr << "Error: n and r must be non-negative integers.\n";
        return;
    }
    if (r_val > n_val) {
        cerr << "Error: r cannot be greater than n.\n";
        return;
    }

    preans = ans;
    ans = factorial(n_val) / (factorial(r_val) * factorial(n_val - r_val));
    cout << "C(" << n_val << ", " << r_val << ") = " << ans << endl;
}

void Combination::arrangement() {
    string n_str, r_str;
    cout << "Enter n: ";
    cin >> n_str;
    cout << "Enter r: ";
    cin >> r_str;

    int n_val = static_cast<int>(parse_input(n_str));
    int r_val = static_cast<int>(parse_input(r_str));

    // Validation
    if (n_val < 0 || r_val < 0) {
        cerr << "Error: n and r must be non-negative integers.\n";
        return;
    }
    if (r_val > n_val) {
        cerr << "Error: r cannot be greater than n.\n";
        return;
    }

    preans = ans;
    ans = factorial(n_val) / factorial(n_val - r_val);
    cout << "A(" << n_val << ", " << r_val << ") = " << ans << endl;
}

void Combination::permutation() {
    string n_str;
    cout << "Enter n: ";
    cin >> n_str;

    int n_val = static_cast<int>(parse_input(n_str));

    // Validation
    if (n_val < 0) {
        cerr << "Error: n must be a non-negative integer.\n";
        return;
    }

    preans = ans;
    ans = factorial(n_val);
    cout << "P(" << n_val << ") = " << ans << endl;
}

void Combination::setMem() {
    string input;
    cout << "Enter a number to store in memory: ";
    cin >> input;
    mem = parse_input(input);
    cout << "Memory set to: " << mem << "\n";
}

void Combination::printMem() {
    cout << "Memory value: " << mem << endl;
}