#ifndef CONVENERGY_H
#define CONVENERGY_H

#include "unitConv.h"

using namespace std;

class convEnergy : public UnitConvert {

private:
    enum EnergyConversion { //dung enum de doi int thanh ten cho de doc
        JL_TO_CL,
        CL_TO_JL,
        JL_TO_WH,
        WH_TO_JL
    };

public:
    void menu() override;
};

#endif
