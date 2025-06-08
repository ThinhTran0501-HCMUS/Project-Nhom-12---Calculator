#ifndef POLYNOMIAL_CAL_H
#define POLYNOMIAL_CAL_H

#include "Calculator_mode.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

#define maximum 50

using namespace std;

class Polynomial : public Calculator_mode {
private:
    char dt[maximum];         // input polynomial as string
    int coeffs[maximum];      // integer coefficients
    float fcoeffs[maximum];   // for division
    int degree;
    int choice;
    string modeName;

public:
    Polynomial();
    virtual ~Polynomial();

    // Core interface
    virtual void welcome() override;
    virtual void parse_operation(string const& str) override;
    virtual void print_name() override;
    virtual void set_choice(int choice) override;
    virtual int get_choice() override;

    // Polynomial logic
    void nhap_dt();
    void rut_gon_dt();
    int lay_bac() const;
    Polynomial cong_dt(Polynomial other);
    Polynomial tru_dt(Polynomial other);
    Polynomial nhan_dt(Polynomial other);
    Polynomial chia_dt(Polynomial other);
    void print() const;
};

#endif