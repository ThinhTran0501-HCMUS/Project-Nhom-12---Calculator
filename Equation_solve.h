#ifndef EQUATION_SOLVE_H
#define EQUATION_SOLVE_H
#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include "Calculator_mode.h"
using namespace std;
class Equation_solve:public Calculator_mode{
    private:
    int choice;
    protected:
    float ans, preans, mem;
    public:
    Equation_solve();
    virtual ~Equation_solve()=default;
    /* Ham dung de nhap du kien input, vi du neu ta nhap la pi
    thi chuong trinh se coi no nhu 3.14159 */
    virtual double parse_input(string const &str);
    // Ham dung de hien thi menu cho moi mode
    virtual void welcome();
    //Ham dung de nhap phep tinh, vi du nhap * chuong trinh se biet la phep nhan
    virtual void parse_operation(string const &str);
    // Ham dung de in ten mode hien tai
    virtual void print_name();
    virtual void set_choice(int choice);
    virtual int get_choice();
};

#endif