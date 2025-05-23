#include "unitConv.h"
#include "convTemp.h"
#include "convLength.h"
#include "convMass.h"
#include "convArea.h"
#include "convVel.h"
#include "convPres.h"
#include "convEnergy.h"
#include "convPow.h"

#include <iostream>
#include <string>  
using namespace std;

double UnitConvert::convert(const string &firstUnit, const string &secondUnit, double inputValue, double conversionFactor, double conversionOffset){
    double result;
    result = inputValue * conversionFactor + conversionOffset;
    cout << inputValue << " " << firstUnit << " = " << result << " "<< secondUnit << endl;
    return result;
}

double UnitConvert::convertByOffset(const string &firstUnit, const string &secondUnit, double inputValue, double conversionFactor, double conversionOffset){
    double result;
    result = (inputValue + conversionOffset) * conversionFactor;
    cout << inputValue << " " << firstUnit << " = " << result << " "<< secondUnit << endl;
    return result;
}

void UnitConvert::welcome(){
    int choice;
    while (true){
        cout<<"Select the type of unit to convert:\n";
        cout<<"1. Temperature\n";
        cout<<"2. Length\n";
        cout<<"3. Area\n";
        cout<<"4. Mass\n";
        cout<<"5. Velocity\n";
        cout<<"6. Pressure\n";
        cout<<"7. Energy\n";
        cout<<"8. Power\n";
        cin >> choice;

    UnitConvert *converter = nullptr;

    switch (choice){
        case 1:
        converter = new convTemp();
        break;
        case 2:
        converter = new convLength();
        break;
        case 3:
        converter = new convArea();
        break;
        case 4:
        converter = new convMass();
        break;
        case 5:
        converter = new convVel();
        break;
        case 6:
        converter = new convPres();
        break;
        case 7:
        converter = new convEnergy();
        break;
        case 8:
        converter = new convPower();
        break;
        default:
        cout<<"Invalid selection!";
        break;
    }

    if (converter) {
        converter->menu();     
        delete converter;   
        }

    cout<<"\nPress Enter to continue";
    cin.ignore(); // if there's leftover input
    cin.get(); 
    }
}   