#include "Basic_calculator.h"
#include "iostream"
int main(){
    Basic_calculator* b;
    string input="" ;
    while (cin>>input && input!="exit"){
        b->welcome();
        b->parse_input(input);
    }
    b->welcome();
}