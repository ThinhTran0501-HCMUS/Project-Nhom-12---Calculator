#include "unitConv.h"
#include <iostream>
#include <string>  
using namespace std;

double UnitConvert::convert(string firstUnit, string secondUnit, double inputValue, double conversionFactor, double conversionOffset){
    double result;
    result = inputValue * conversionFactor + conversionOffset;
    cout << inputValue << " " << firstUnit << " = " << result << " "<< secondUnit << endl;
    return result;
}

double UnitConvert::convertByOffset(string firstUnit, string secondUnit, double inputValue, double conversionFactor, double conversionOffset){
    double result;
    result = (inputValue + conversionOffset) * conversionFactor;
    cout << inputValue << " " << firstUnit << " = " << result << " "<< secondUnit << endl;
    return result;
}

