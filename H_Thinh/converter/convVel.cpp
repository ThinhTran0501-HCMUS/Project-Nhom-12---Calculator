#include "convVel.h"
#include <iostream>
#include <limits>

using namespace std;

void convVel::menu() {
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

    VelocityConversion choice = static_cast<VelocityConversion>(rawChoice); 

    switch (rawChoice) {
            case MPS_TO_FPS:
                convert("m/s", "ft/s",userInputValue , 3.28084, 0);
                break;
            case FPS_TO_MPS:
                convert("ft/s", "m/s",userInputValue , 1/3.28084, 0);
                break;
            case KPH_TO_MPS:
                convert("km/h", "m/s",userInputValue , 5/18, 0);
                break;
            case MPS_TO_KPH:
                convert("m/s", "km/h",userInputValue , 3.6, 0);
                break;
            case KT_TO_KPH:
                convert("Knot", "km/h",userInputValue , 1.852, 0);
                break;
            case KPH_TO_KT:
                convert("km/h", "Knot",userInputValue , 1/1.852, 0);
                break;
            default:
                cout << "Invalid option.\n";
                break;
        }
}
