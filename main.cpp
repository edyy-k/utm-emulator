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
        std::cout << std::endl;

        // TODO: check if line is a binary code

        UniversalTM universalTM;
        universalTM.initialize(line);

        Emulator emulator(&universalTM);
        emulator.run(stepMode);

        if (!stepMode)
        {
            universalTM.printTape();
            std::cout << "\nSTEP " << emulator.getAmountSteps();
        }

        std::cout << "\n> " << (emulator.isAccepted() ? "ACCEPTED" : "REJECTED") << "\n\n";
    }
}
