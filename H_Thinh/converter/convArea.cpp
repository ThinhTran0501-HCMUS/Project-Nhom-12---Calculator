#include "convArea.h"
#include <iostream>
#include <limits>

using namespace std;

void convArea::menu() {
    int rawChoice;
    double userInputValue;

    cout << "Select the conversion: \n";
    cout<<"1. Square Meter to Square Feet\n";
    cout<<"2. Square Feet to Square Meter\n";
    cout<<"3. Square Meter to Square Yard\n";
    cout<<"4. Square Yard to Square Meter\n";
    cout<<"5. Square Kilometer to Square Mile\n";
    cout<<"6. Square Mile to Square Kilometer\n";
    cout<<"7. Square Kilometer to Hectare\n";
    cout<<"8. Square Meter to Football fields\n";  

    cin >> rawChoice;

    cout << "Enter the value to convert: ";
    cin >>userInputValue;

    AreaConversion choice = static_cast<AreaConversion>(rawChoice); 

    switch (rawChoice) {
            case SQM_TO_SQFT:
                convert("Square Meter", "Square Feet",userInputValue , 10.7639, 0);
                break;
            case FTSQ_TO_SQM:
                convert("Square Feet", "Square Meter",userInputValue ,  0.092903, 0);
                break;
            case SQM_TO_SQYD:
                convert("Square Meter", "Square Yard",userInputValue ,  1.19599 , 0);
                break;
            case SQYD_TO_SQM:
                convert("Square Yard", "Square Meter",userInputValue ,  0.83613 , 0);
                break;
            case SQKM_TO_SQML:
                convert("Square Kilometer", "Square Mile",userInputValue ,  0.386102, 0);
                break;
            case SQML_TO_SQKM:
                convert("Square Mile", "Square Kilometer",userInputValue ,  2.5899, 0);
                break;
            case SQKM_TO_HC:
                convert("Square Kilometer", "Hectare",userInputValue ,  100, 0);
                break;
            case SQM_TO_FB:
                convert("Square Kilometer", "Football fields",userInputValue ,  0.00714, 0);
                break;
            default:
                cout << "Invalid option.\n";
                break;
        }
}