#ifndef QUADRATIC_EQUA_H
#define QUADRATIC_EQUA_H

#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <complex>
#include "Equation_solve.h"
using namespace std;

class Quadratic_equa : public Equation_solve {
protected:
    double a, b, c;
    string modename;

public:
    Quadratic_equa();
    virtual ~Quadratic_equa()=default;

    void set_mem();
    void print_mem();

    virtual void welcome() override;
    void parse_operation(const string& str) override;
    virtual void The_solver();
};

#endif
