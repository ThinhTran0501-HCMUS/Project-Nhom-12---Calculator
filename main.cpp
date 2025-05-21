#include "Basic_calculator.h"
#include "iostream"
int main(){
    Basic_calculator* b;
    std::string input="" ;
     b->welcome();
    while (std::cin>>input &&std::cout<<"\n>>> "&&true ){
       if (input=="Exit"||input=="exit"){
        std::cout<<"Exit basic calculator"<<std::endl;
        break;
       }
        b->parseOperation(input);
    }
   


}