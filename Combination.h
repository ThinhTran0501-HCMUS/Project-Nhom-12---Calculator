#ifndef COMBINATION_H
#define COMBINATION_H

#include "Calculator_mode.h"
#include <string>
using namespace std;
class Combination : public Calculator_mode {
protected:
    int ans;
    int preans;
    int mem;
    string modeName;
    int factorial(int n);

public:
    Combination();
    virtual ~Combination()=default;

    double parse_input(const string& str) ;
    void welcome() ;
    void parse_operation(const string& op) ;

    void combi_cal();
    void arrangement();
    void permutation();

    void setMem();         
    void printMem();
};
#endif