#ifndef THREE_VARS_H
#define THREE_VARS_H

#include "Two_vars.h"

class Three_vars : public Two_vars {
private:
    float a1, b1, c1, d1;
    float a2, b2, c2, d2;
    float a3, b3, c3, d3;
    string modename;

public:
    Three_vars();
    virtual ~Three_vars()=default;
    void welcome() override;
    void The_solver() override;
    void parse_operation(const string& str) override;
};

#endif