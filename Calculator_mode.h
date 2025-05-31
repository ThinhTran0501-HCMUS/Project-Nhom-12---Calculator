#ifndef CALCULATOR_MODE_H
#define CALCULATOR_MODE_H
#include <string>
#include <array>
#include <cmath>
#include <iostream>
using namespace std;
class Calculator_mode{
    private:
    int choice;
    public:
    Calculator_mode();
    virtual ~Calculator_mode()=default;
    /* Ham dung de nhap du kien input, vi du neu ta nhap la pi
    thi chuong trinh se coi no nhu 3.14159 */
    virtual double parse_input(string const &str);
    // Ham dung de hien thi menu cho moi mode
    virtual void welcome();
    //Ham dung de nhap phep tinh, vi du nhap * chuong trinh se biet la phep nhan
    virtual void parse_operation(string const &str);
    // Ham dung de in ten mode hien tai
    virtual void print_name();
    //Ham dung de thiet lap va hien thi lua chon
   virtual void set_choice(int choice);
   virtual int get_choice();
};

#endif