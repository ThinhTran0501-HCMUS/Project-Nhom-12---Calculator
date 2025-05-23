#ifndef CONVPRES_H
#define CONVPRES_H

#include "unitConv.h"

using namespace std;

class convPres : public UnitConvert {

private:
    enum PresConversion { //dung enum de doi int thanh ten cho de doc
        ATM_TO_PA,
        PA_TO_ATM,
        KGF_TO_PA,
        PA_TO_KGF
    };

public:
    void menu() override;
};

#endif
