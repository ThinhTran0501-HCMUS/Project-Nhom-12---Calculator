#ifndef BASE_H
#define BASE_H

#include "Calculator_mode.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

const char digit[] = "0123456789ABCDEF";

class Base : public Calculator_mode {
private:
    int choice;
    string modeName;
    string bin, dec, oct, hex, input;

    void setBin();
    void setDec();
    void setHex();
    void setOct();

    int To_Dec(string input, int base);
    string To_BaseOfN(int number, int base);
    bool isValidForBase(const string& input, int base);

public:
    Base();
    virtual ~Base() = default;

    virtual void welcome() override;
    virtual void parse_operation(string const& str) override;
    virtual void print_name() override;
    virtual void set_choice(int choice) override;
    virtual int get_choice() override;

    void display();
};

#endif