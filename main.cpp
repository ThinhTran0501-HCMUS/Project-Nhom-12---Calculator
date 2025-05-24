#include "Basic_calculator.h"
#include "iostream"
int main(){

    Basic_calculator* b=new Basic_calculator;
    std::string input="" ;
    b->welcome();
    while (std::cout<<"\n>>> "&&std::cin>>input &&true ){
       if (input=="Exit"||input=="exit"){
        std::cout<<"Exit basic calculator"<<std::endl;
        break;
       }
        b->parseOperation(input);
    }
   


}