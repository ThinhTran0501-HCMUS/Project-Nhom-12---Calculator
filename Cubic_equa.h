#ifndef CUBIC_EQUA_H
#define CUBIC_EQUA_H

#include <string>
#include <complex>
#include "Equation_solve.h"

using namespace std;

class Cubic_equa : public Equation_solve {
protected:
    double a, b, c, d;
    string modename;

public:
    Cubic_equa();
    virtual ~Cubic_equa() = default;

    void set_mem();
    void print_mem();

    virtual void welcome() override;
    void parse_operation(const string& str) override;
    virtual void The_solver();
};

#endif