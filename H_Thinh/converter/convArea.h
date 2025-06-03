#ifndef CONVAREA_H
#define CONVAREA_H

#include "unitConv.h"

using namespace std;

class convArea : public UnitConvert {

private:
    enum AreaConversion { //dung enum de doi int thanh ten cho de doc
        SQM_TO_SQFT = 1,
        FTSQ_TO_SQM,
        SQM_TO_SQYD,
        SQYD_TO_SQM,
        SQKM_TO_SQML,
        SQML_TO_SQKM,
        SQKM_TO_HC,
        SQM_TO_FB
    };

public:
    void menu() override;
};

#endif