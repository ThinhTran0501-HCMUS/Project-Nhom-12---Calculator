#ifndef CONVTEMP_H
#define CONVTEMP_H

#include "unitConv.h"

using namespace std;

class convTemp : public UnitConvert {

private:
    enum TempConversion { //dung enum de doi int thanh ten cho de doc
        C_TO_F = 1,
        F_TO_C,
        C_TO_K,
        K_TO_C,
        K_TO_F,
        F_TO_K
    };

public:
    void menu() override;
};

#endif