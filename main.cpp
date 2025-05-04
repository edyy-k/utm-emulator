#include "UniversalTM.h"
#include "Emulator.h"

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    bool stepMode = false;
    std::string test = "";

    
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg == "--step-mode")
            stepMode = true;
    }

    std::string line;
    while (std::getline(std::cin, line))
    {
        UniversalTM universalTM;
        universalTM.initialize(line);

        Emulator emulator(&universalTM);
        emulator.run();

        universalTM.printTape();
    }
}
