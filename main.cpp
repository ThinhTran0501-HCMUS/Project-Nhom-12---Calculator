#include "Basic_calculator.h"
#include <cmath>
#include <array>
#include <string>
#include <iostream>
int main(){
    Basic_calculator* b;
    string input="" ;
    b->welcome();
    while (cin>>input && input!="exit"){
        b->parse_input(input);
        b->welcome();
    }
    cout<<"\n Exit programe\n";
}