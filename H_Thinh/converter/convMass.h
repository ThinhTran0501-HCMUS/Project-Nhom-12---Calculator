#ifndef CONVMASS_H
#define CONVMASS_H

#include "unitConv.h"

using namespace std;

class convMass : public UnitConvert {

private:
    enum massConversion { //dung enum de doi int thanh ten cho de doc
        KG_TO_LB,
        LB_TO_KG,
        GR_TO_OZ,
        OZ_TO_GR
    };

public:
    void menu() override;
};

#endif