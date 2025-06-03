#ifndef QUADRATIC_INE_H
#define QUADRATIC_INE_H

#include <string>
#include "Equation_solve.h"

using namespace std;

class Quadratic_ine : public Equation_solve {
protected:
    double a, b, c;
    string modename;
    string op;

public:
    Quadratic_ine();
    virtual ~Quadratic_ine() = default;

    void set_mem();
    void print_mem();

    virtual void welcome() override;
    void parse_operation(const string& str) override;
    virtual void The_solver();
    void validate_operator(const string& input);
};

#endif
