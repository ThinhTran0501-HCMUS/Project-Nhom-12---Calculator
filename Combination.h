#ifndef COMBINATION_H
#define COMBINATION_H

#include "calculator.h"
#include <string>
using namespace std;
class Combination : public Calculator {
private:
    int ans;
    int preans;

    int factorial(int n);

public:
    Combination();
    virtual ~Combination();

    double parseInput(string& input) ;
    void welcome() ;
    void parseOperation(string& op) ;

    void combi_cal(int n, int r);
    void arrangement(int n, int r);
    void permutation(int n);

    void setMem();         
    void printMem();
};
#endif
