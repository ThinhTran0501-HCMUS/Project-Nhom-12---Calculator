#include "Basic_calculator.h"
#include "iostream"
int main(){
    Basic_calculator* b;
    std::string input="" ;
    while (std::cin>>input && input!="exit"){
        b->welcome();
        b->parse_input(input);
    }
   


}