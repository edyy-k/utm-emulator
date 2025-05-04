#include "Emulator.h"

#include <iostream>

void Emulator::run()
{
    std::vector<Transition> transitions = universalTM->getTransitions();

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
            deadEnd = false;
            break;
        }
    } while (!deadEnd);
}
