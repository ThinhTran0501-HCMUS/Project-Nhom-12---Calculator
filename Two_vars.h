#ifndef TWO_VAR_H
#define TWO_VAR_H

#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Equation_solve.h"

using namespace std;

class Two_vars : public Equation_solve {
private:
    string modeName;
    float a1, b1, c1, a2, b2, c2;

public:
    Two_vars();
    virtual ~Two_vars() = default;

    virtual double parse_input(const string& str) override;
    virtual void welcome() override;
    virtual void parse_operation(const string& str) override;
    virtual void print_name() override;

    void set_mem();
    void print_mem();
    virtual void The_solver();
};

#endif