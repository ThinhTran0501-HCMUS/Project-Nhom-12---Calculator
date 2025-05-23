#include "convEnergy.h"
#include <iostream>
#include <limits>

using namespace std;

void convEnergy::menu() {
    int rawChoice;
    double userInputValue;

    cout << "Select the conversion: \n";
    cout<<"1. Joules to Calories\n";
    cout<<"2. Calories to Joules\n";
    cout<<"3. Joules to Watt-Hour\n";
    cout<<"4. Watt-Hour to Joules\n";      

    cin >> rawChoice;

    cout << "Enter the value to convert: ";
    cin >>userInputValue;

    EnergyConversion choice = static_cast<EnergyConversion>(rawChoice); 

    switch (rawChoice) {
            case JL_TO_CL:
                convert("Joules", "Calories",userInputValue , 0.23900574, 0);
                break;
            case CL_TO_JL:
                convert("Calories", "Joules",userInputValue , 1/0.23900574, 0);
                break;
            case JL_TO_WH:
                convert("Joules", "Watt-Hour",userInputValue , 1/3600, 0);
                break;
            case WH_TO_JL:
                convert("Watt-Hour", "Joules",userInputValue , 3600, 0);
                break;
            default:
                cout << "Invalid option.\n";
                break;
        }
}
