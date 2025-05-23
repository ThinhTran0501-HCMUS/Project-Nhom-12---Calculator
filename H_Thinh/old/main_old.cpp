#include <iostream>
#include "unitConv.h"
#include <string>
using namespace std;

void physConv(){
    int userInputValue; //me when the
    //todo: play little dark age reverb slowed https://youtu.be/K3AxYP2G2c8
    UnitConvert conversion;
    int selOne, selTwo;
    cout<<"Select the type of unit to convert:\n";
    cout<<"1. Temperature\n";
    cout<<"2. Length\n";
    cout<<"3. Area\n";
    cout<<"4. Mass\n";
    cout<<"5. Velocity\n";
    cout<<"6. Pressure\n";
    cout<<"7. Energy\n";
    cout<<"8. Power\n";
    cin >> selOne;

    switch (selOne) //selecting the type
    {
    case 1:
        cout << "Select the conversion: \n";
        cout<<"1. Celsius to Fahrenheit\n";
        cout<<"2. Fahrenheit to Celsius\n";
        cout<<"3. Celsius to Kelvin\n";
        cout<<"4. Kelvin to Celsius\n";
        cout<<"5. Kelvin to Fahrenheit\n";
        cout<<"6. Fahrenheit to Kelvin\n";         
        cin >> selTwo;       
        break;
    
    case 2:
        cout << "Select the conversion: \n";
        cout<<"1. Meter to Feet\n";
        cout<<"2. Feet to Meter\n";
        cout<<"3. Meter to Yard\n";
        cout<<"4. Yard to Meter\n";
        cout<<"5. Kilometer to Mile\n";
        cout<<"6. Mile to Kilometer\n"; 
        cout<<"7. Centimeter to Standard Reference Banana\n"; 
        cin >> selTwo;       
        break;
    
    case 3:
        cout << "Select the conversion: \n";
        cout<<"1. Square Meter to Square Feet\n";
        cout<<"2. Square Feet to Square Meter\n";
        cout<<"3. Square Meter to Square Yard\n";
        cout<<"4. Square Yard to Square Meter\n";
        cout<<"5. Square Kilometer to Square Mile\n";
        cout<<"6. Square Mile to Square Kilometer\n";
        cout<<"7. Square Kilometer to Hectare\n";
        cout<<"8. Square Meter to Football fields\n";
        cin >> selTwo;       
        break;

    case 4:
        cout << "Select the conversion: \n";
        cout<<"1. Kilogram to Pound\n";
        cout<<"2. Pound to Kilogram\n";
        cout<<"3. Gram to Ounce\n";
        cout<<"4. Ounce to Gram\n";
        cin >> selTwo;       
        break;

    case 5:
        cout << "Select the conversion: \n";
        cout<<"1. m/s to ft/s\n";
        cout<<"2. ft/s to m/s\n";
        cout<<"3. km/h to m/s\n";
        cout<<"4. m/s to km/h\n";
        cout<<"5. Knot to km/h\n";
        cout<<"6. km/h to Knot\n";
        cin >> selTwo;       
        break;

    case 6:
        cout << "Select the conversion: \n";
        cout<<"1. atm to Pa\n";
        cout<<"2. Pa to atm\n";
        cout<<"3. kgf/cm2 to Pa\n";
        cout<<"4. Pa to kgf/cm2\n";
        cin >> selTwo;       
        break;

    case 7:
        cout << "Select the conversion: \n";
        cout<<"1. Joules to Calories\n";
        cout<<"2. Calories to Joules\n";
        cout<<"3. Joules to Watt-Hour\n";
        cout<<"4. Watt-Hour to Joules\n";
        cin >> selTwo;       
        break;    
        
    case 8:
        cout << "Select the conversion: \n";
        cout<<"1. Horse power to kiloWatt\n";
        cout<<"2. kiloWatt to Horse power\n";
        cin >> selTwo;       
        break;  

    default:
        cout << "Invalid selection. ";
        break;
    }

//doing the converting

    if (selOne==1){ //option 1
        cout << "Enter the value to convert: ";
        if (selTwo==1){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Celsius", "Fahrenheit",userInputValue , 1.8, 32);
        }
        else if (selTwo==2){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convertByOffset("Fahrenheit", "Celsius",userInputValue , 0.555556, -32);
        }
        else if (selTwo==3){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Celsius", "Kelvin",userInputValue , 1, 273);
        }
        else if (selTwo==4){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Kelvin", "Celsius",userInputValue , 1, -273);
        }
        else if (selTwo==5){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Kelvin", "Fahrenheit",userInputValue, 1.8,-459.4);
        }
        else if (selTwo==6){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convertByOffset("Fahrenheit", "Kelvin",userInputValue , 0.555556, -32);
        }
        else if (selTwo==6){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convertByOffset("Fahrenheit", "Kelvin",userInputValue , 0.555556, -32);
        }
        else cout << "Invalid selection";
    }
    else if (selOne==2){ //option 2
        cout << "Enter the value to convert: ";
        if (selTwo==1){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Meter", "Feet",userInputValue , 3.28084, 0);
        }
        else if (selTwo==2){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Feet", "Meter",userInputValue , 0.3048, 0);
        }
        else if (selTwo==3){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Meter", "Yard",userInputValue , 1.0936132983, 0);
        }
        else if (selTwo==4){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Meter", "Yard",userInputValue , 0.9144, 0);
        }
        else if (selTwo==5){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Kilometer", "Mile",userInputValue , 0.6214, 0);
        }
        else if (selTwo==6){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Mile", "Kilometer",userInputValue , 1.609344, 0);
        }
        else if (selTwo==7){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Centimeter", "Standard Reference Banana",userInputValue , 1/18.55236432, 0);
        }
        else cout << "Invalid selection";
    }
    else if (selOne==3){ //option 3
        cout << "Enter the value to convert: ";
        if (selTwo==1){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Square Meter", "Square Feet",userInputValue , 10.7639, 0);
        }
        else if (selTwo==2){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Square Feet", "Square Meter",userInputValue ,  0.092903, 0);
        }
        else if (selTwo==3){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Square Meter", "Square Yard",userInputValue ,  1.19599 , 0);
        }
        else if (selTwo==4){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Square Yard", "Square Meter",userInputValue ,  0.83613 , 0);
        }
        else if (selTwo==5){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Square Kilometer", "Square Mile",userInputValue ,  0.386102, 0);
        }
        else if (selTwo==6){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Square Mile", "Square Kilometer",userInputValue ,  2.5899, 0);
        }
        else if (selTwo==7){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Square Kilometer", "Hectare",userInputValue ,  100, 0);
        }
        else if (selTwo==8){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Square Kilometer", "Football fields",userInputValue ,  0.00714, 0);
        }
        else cout << "Invalid selection." << endl;
    }
    else if (selOne==4){ //option 4
        cout << "Enter the value to convert: ";
        if (selTwo==1){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Kilogram", "Pound",userInputValue , 2.2046226218, 0);
        }
        else if (selTwo==2){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Pound", "Kilogram",userInputValue , 1/2.2046226218, 0);
        }
        else if (selTwo==3){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Gram", "Ounce",userInputValue , 0.03527396195, 0);
        }
        else if (selTwo==4){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Gram", "Ounce",userInputValue , 1/0.03527396195, 0);
        }
        else cout << "Invalid selection." << endl;
    }
    else if (selOne==5){ //option 5
        cout << "Enter the value to convert: ";
        if (selTwo==1){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("m/s", "ft/s",userInputValue , 3.28084, 0);
        }
        else if (selTwo==2){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("ft/s", "m/s",userInputValue , 1/3.28084, 0);
        }
        else if (selTwo==3){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("km/h", "m/s",userInputValue , 5/18, 0);
        }
        else if (selTwo==4){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("m/s", "km/h",userInputValue , 3.6, 0);
        }
        else if (selTwo==5){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Knot", "km/h",userInputValue , 1.852, 0);
        }
        else if (selTwo==6){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("km/h", "Knot",userInputValue , 1/1.852, 0);
        }
        else cout << "Invalid selection." << endl;
    }

    else if (selOne==6){ //option 6
        cout << "Enter the value to convert: ";
        if (selTwo==1){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("atm", "Pa",userInputValue , 101325, 0);
        }
        else if (selTwo==2){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Pa", "atm",userInputValue , 0.000009869233, 0);
        }

        else if (selTwo==3){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("kgf/cm2", "Pa",userInputValue , 98066.5, 0);
        }
        else if (selTwo==4){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("kgf/cm2", "Pa",userInputValue , 1/98066.5, 0);
        }
        else cout << "Invalid selection." << endl;
    }
    else if (selOne==7){ //option 7
        cout << "Enter the value to convert: ";
        if (selTwo==1){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Joules", "Calories",userInputValue , 0.23900574, 0);
        }
        else if (selTwo==2){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Joules", "Calories",userInputValue , 1/0.23900574, 0);
        }
        else if (selTwo==3){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Joules", "Watt-Hour",userInputValue , 1/3600, 0);
        }
        else if (selTwo==4){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Watt-Hour", "Joules",userInputValue , 3600, 0);
        }
        else cout << "Invalid selection." << endl;
    }

    else if (selOne==8){ //option 6
        cout << "Enter the value to convert: ";
        if (selTwo==1){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("Horse power", "kiloWatt",userInputValue , 0.74569987, 0);
        }
        if (selTwo==2){ //add more of this to have more options
            cin >> userInputValue;
            conversion.convert("kiloWatt", "Horse power",userInputValue , 1.34102209, 0);
        }
        else cout << "Invalid selection." << endl;
    }   
}


int main(){
    physConv();
    
}