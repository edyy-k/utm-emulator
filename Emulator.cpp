#include "Emulator.h"

#include <iostream>
#include <chrono>
#include <thread>

extern const uint ACCEPTED_STATE = 2;

void Emulator::printStep()
{
    universalTM->printTape();
    std::cout << "\n\rSTEP " << getAmountSteps() << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
}

void Emulator::run(bool stepMode)
{
    std::vector<Transition> transitions = universalTM->getTransitions();

    if (stepMode)
    {
        printStep();
    }

    bool deadEnd = true;
    do
    {
        deadEnd = true;
        for (Transition t : transitions)
        {
            if (t.state != universalTM->getCurrentState() || t.symbolToRead != universalTM->read())
            {
                continue;
            }

            universalTM->write(t.symbolToWrite);

            switch (t.direction)
            {
            case Direction::Left:
                universalTM->goLeft();
                break;
            case Direction::Right:
                universalTM->goRight();
                break;
            }

            universalTM->setCurrentState(t.nextState);
            amountSteps++;
            deadEnd = false;

            if (stepMode)
            {
                // move cursor two lines up
                std::cout << "\033[2A";
                printStep();
            }

            break;
        }
    } while (!deadEnd);
}

uint Emulator::getAmountSteps()
{
    return amountSteps;
}

bool Emulator::isAccepted()
{
    return (universalTM->getCurrentState() == ACCEPTED_STATE);
}
