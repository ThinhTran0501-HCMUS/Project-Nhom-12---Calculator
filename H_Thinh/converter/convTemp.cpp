#include "convTemp.h"
#include <iostream>
#include <limits>

using namespace std;

void convTemp::menu() {
    int rawChoice;
    double inputValue;

    cout << "Select the conversion (1-6): \n";
    cout<<"1. Celsius to Fahrenheit\n";
    cout<<"2. Fahrenheit to Celsius\n";
    cout<<"3. Celsius to Kelvin\n";
    cout<<"4. Kelvin to Celsius\n";
    cout<<"5. Kelvin to Fahrenheit\n";
    cout<<"6. Fahrenheit to Kelvin\n";    

    cin >> rawChoice;

    cout << "Enter the value to convert: ";
    cin >>inputValue;

    TempConversion choice = static_cast<TempConversion>(rawChoice); 

    switch (rawChoice) {
            case C_TO_F:
                convert("Celsius", "Fahrenheit", inputValue, 1.8, 32);
                break;
            case F_TO_C:
                convertByOffset("Fahrenheit", "Celsius", inputValue, 0.555556, -32);
                break;
            case C_TO_K:
                convert("Celsius", "Kelvin", inputValue, 1, 273.15);
                break;
            case K_TO_C:
                convert("Kelvin", "Celsius", inputValue, 1, -273.15);
                break;
            case K_TO_F:
                convert("Kelvin", "Fahrenheit", inputValue, 1.8, -459.67);
                break;
            case F_TO_K:
                convertByOffset("Fahrenheit", "Kelvin", inputValue, 0.555556, -32);
                break;
            default:
                cout << "Invalid option.\n";
                break;
        }




}