#include "UniversalTM.h"
#include "Emulator.h"

#include <iostream>
#include <vector>
#include <regex>

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

        if (!std::regex_match(line, std::regex("^[01]+$")))
        {
            std::cerr << "Error: invalid input\n";
            std::exit(EXIT_FAILURE);
        }

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
