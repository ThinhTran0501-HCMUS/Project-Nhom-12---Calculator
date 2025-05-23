#include "convPres.h"
#include <iostream>
#include <limits>

using namespace std;

void convPres::menu() {
    int rawChoice;
    double userInputValue;

    cout << "Select the conversion: \n";
    cout<<"1. m/s to ft/s\n";
    cout<<"2. ft/s to m/s\n";
    cout<<"3. km/h to m/s\n";
    cout<<"4. m/s to km/h\n";
    cout<<"5. Knot to km/h\n";
    cout<<"6. km/h to Knot\n";       

    cin >> rawChoice;

    cout << "Enter the value to convert: ";
    cin >>userInputValue;

    PresConversion choice = static_cast<PresConversion>(rawChoice); 

    switch (rawChoice) {
            case ATM_TO_PA:
                convert("atm", "Pa",userInputValue , 101325, 0);
                break;
            case PA_TO_ATM:
                convert("Pa", "atm",userInputValue , 0.000009869233, 0);
                break;
            case KGF_TO_PA:
                convert("kgf/cm2", "Pa",userInputValue , 98066.5, 0);
                break;
            case PA_TO_KGF:
                convert("kgf/cm2", "Pa",userInputValue , 1/98066.5, 0);
                break;
            default:
                cout << "Invalid option.\n";
                break;
        }
}
