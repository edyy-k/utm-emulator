#include "UniversalTM.h"

#ifndef EMULATOR_H
#define EMULATOR_H

class Emulator
{
private:
    UniversalTM *universalTM;

public:
    Emulator(UniversalTM *utm) : universalTM(utm) {};
    void run();
};

#endif
