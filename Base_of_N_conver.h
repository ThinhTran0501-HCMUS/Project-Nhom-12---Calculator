#ifndef BASE_H
#define BASE_H

#include<iostream>

#include<vector>
#include <string.h>
#include <math.h>

using namespace std;
const char digit[]="0123456789ABCDEF";
class Base{
    private:
    string bin,dec,oct,hex;
    string input;
    public:
    Base(int choice);

    //hàm nhập bin,dec,hex,oct
    void setBin();
    void setDec();
    void setHex();
    void setOct();

    int To_Dec(string input, int base_conver);// cơ số bất kỳ ngược lại 10

    string To_BaseOfN(int number, int base);//cơ số 10 -> base bất kỳ

    bool isValidForBase(const string& input, int base);

    void display();
};

#endif