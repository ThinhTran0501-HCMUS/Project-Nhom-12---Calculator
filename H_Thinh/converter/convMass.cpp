#include "convMass.h"
#include <iostream>
#include <limits>

using namespace std;

void convMass::menu() {
    int rawChoice;
    double userInputValue;

    cout << "Select the conversion: \n";
    cout<<"1. Kilogram to Pound\n";
    cout<<"2. Pound to Kilogram\n";
    cout<<"3. Gram to Ounce\n";
    cout<<"4. Ounce to Gram\n";  

    cin >> rawChoice;

    cout << "Enter the value to convert: ";
    cin >>userInputValue;

    massConversion choice = static_cast<massConversion>(rawChoice); 

    switch (rawChoice) {
            case KG_TO_LB:
                convert("Kilogram", "Pound",userInputValue , 2.2046226218, 0);
                break;
            case LB_TO_KG:
                convert("Pound", "Kilogram",userInputValue , 1/2.2046226218, 0);
                break;
            case GR_TO_OZ:
                convert("Gram", "Ounce",userInputValue , 0.03527396195, 0);
                break;
            case OZ_TO_GR:
                convert("Gram", "Ounce",userInputValue , 1/0.03527396195, 0);                break;
            default:
                cout << "Invalid option.\n";
                break;
        }
}
