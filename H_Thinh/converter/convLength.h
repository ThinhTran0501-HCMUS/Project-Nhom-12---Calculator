#ifndef CONVLENGTH_H
#define CONVLENGTH_H

#include "unitConv.h"

using namespace std;

class convLength : public UnitConvert {

private:
    enum LengthConversion { //dung enum de doi int thanh ten cho de doc
        M_TO_FT = 1,
        FT_TO_M,
        M_TO_YD,
        YD_TO_M,
        KM_TO_ML,
        ML_TO_KM,
        CM_TO_BN
    };

public:
    void menu() override;
};

#endif