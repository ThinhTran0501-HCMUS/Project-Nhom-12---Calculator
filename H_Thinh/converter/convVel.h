#ifndef CONVVEL_H
#define CONVVEL_H

#include "unitConv.h"

using namespace std;

class convVel : public UnitConvert {

private:
    enum VelocityConversion { //dung enum de doi int thanh ten cho de doc
        MPS_TO_FPS,
        FPS_TO_MPS,
        KPH_TO_MPS,
        MPS_TO_KPH,
        KT_TO_KPH,
        KPH_TO_KT
    };

public:
    void menu() override;
};

#endif
