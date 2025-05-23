#ifndef CONVPOW_H
#define CONVPOW_H

#include "unitConv.h"

using namespace std;

class convPower : public UnitConvert {

private:
    enum PowerConversion { //dung enum de doi int thanh ten cho de doc
        HP_TO_KW,
        KW_TO_HP
    };

public:
    void menu() override;
};

#endif
