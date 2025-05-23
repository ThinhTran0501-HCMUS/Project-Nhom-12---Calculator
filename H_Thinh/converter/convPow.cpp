#include "convPow.h"
#include <iostream>
#include <limits>

using namespace std;

void convPower::menu() {
    int rawChoice;
    double userInputValue;

    cout << "Select the conversion: \n";
    cout<<"1. Horse power to kiloWatt\n";
    cout<<"2. kiloWatt to Horse power\n";      

    cin >> rawChoice;

    cout << "Enter the value to convert: ";
    cin >>userInputValue;

    PowerConversion choice = static_cast<PowerConversion>(rawChoice); 

    switch (rawChoice) {
            case HP_TO_KW:
                convert("Horse power", "KiloWatt",userInputValue , 0.74569987, 0);
                break;
            case KW_TO_HP:
                convert("kiloWatt", "Horse power",userInputValue , 1.34102209, 0);
                break;
            default:
                cout << "Invalid option.\n";
                break;
        }
}
