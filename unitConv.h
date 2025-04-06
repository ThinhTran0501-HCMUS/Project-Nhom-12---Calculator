#include <iostream>
#include <string>
#ifndef UNITCONV_H
#define UNITCONV_H
using namespace std;

class UnitConvert{
    private:
    std::string firstUnit;
    std::string secondUnit; //ko dung trong tinh toan, chi dung de hien thi
    double conversionFactor; //dung de so sanh 1 dv nay voi dv kia
    double conversionOffset=0; // dung cho cac don vi co cung thang nhung offset (vd kelvin -> cel-273)
    
    public:
    UnitConvert(){
        firstUnit="empty";
        secondUnit="empty";
        conversionFactor = 1;
        conversionOffset=0;
    }

    double convert(const string firstUnit, const string secondUnit, double inputValue, double conversionFactor, double conversionOffset); 
    double convertByOffset(const string firstUnit, const string secondUnit, double inputValue, double conversionFactor, double conversionOffset); //tru offset truoc roi moi nhan cho factor
    
    //co the dung trong da so truong hop doi don vi tuyen tinh
    //todo: lam ham tong quat cho truong hop log, rad,...    
};
#endif


