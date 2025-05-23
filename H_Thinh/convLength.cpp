#include "convLength.h"
#include <iostream>
#include <limits>

using namespace std;

void convLength::menu() {
    int rawChoice;
    double userInputValue;

    cout << "Select the conversion: \n";
    cout<<"1. Meter to Feet\n";
    cout<<"2. Feet to Meter\n";
    cout<<"3. Meter to Yard\n";
    cout<<"4. Yard to Meter\n";
    cout<<"5. Kilometer to Mile\n";
    cout<<"6. Mile to Kilometer\n"; 
    cout<<"7. Centimeter to Standard Reference Banana\n";   

    cin >> rawChoice;

    cout << "Enter the value to convert: ";
    cin >>userInputValue;

    LengthConversion choice = static_cast<LengthConversion>(rawChoice); 

    switch (rawChoice) {
            case M_TO_FT:
                convert("Meter", "Feet",userInputValue , 3.28084, 0);
                break;
            case FT_TO_M:
                convert("Feet", "Meter",userInputValue , 0.3048, 0);
                break;
            case M_TO_YD:
                convert("Meter", "Yard",userInputValue , 1.0936132983, 0);
                break;
            case YD_TO_M:
                convert("Yard", "Meter",userInputValue , 0.9144, 0);
                break;
            case KM_TO_ML:
                convert("Kilometer", "Mile",userInputValue , 0.6214, 0);
                break;
            case ML_TO_KM:
                convert("Mile", "Kilometer",userInputValue , 1.609344, 0);
                break;
            case CM_TO_BN:
                convert("Centimeter", "Standard Reference Banana(s)",userInputValue , 1/18.55236432, 0);
                break;
            default:
                cout << "Invalid option.\n";
                break;
        }




}