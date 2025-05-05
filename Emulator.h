#include "UniversalTM.h"

#ifndef EMULATOR_H
#define EMULATOR_H

typedef unsigned int uint;

class Emulator
{
private:
    UniversalTM *universalTM;
    uint amountSteps;
    void printStep();

public:
    Emulator(UniversalTM *utm) : universalTM(utm), amountSteps(0) {};
    void run(bool stepMode = false);
    uint getAmountSteps();
};

#endif
