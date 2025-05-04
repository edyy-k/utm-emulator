#include "UniversalTM.h"

#include <sstream>
#include <iostream>

const std::vector<char> SYMBOL_MAP = {'0', '1', '_'};
const std::vector<Direction> DIRECTION_MAP = {Direction::Left, Direction::Right};

void UniversalTM::parseTransition(const std::string &code)
{
    std::istringstream iss(code);
    std::string line;
    std::vector<std::string> tokens;

    while (getline(iss, line, '1'))
    {
        tokens.push_back(line);
    }

    Transition transition;
    transition.state = tokens[0].length();
    transition.symbolToRead = SYMBOL_MAP[tokens[1].length() - 1];
    transition.nextState = tokens[2].length();
    transition.symbolToWrite = SYMBOL_MAP[tokens[3].length() - 1];
    transition.direction = DIRECTION_MAP[tokens[4].length() - 1];
    transitions.push_back(transition);
}

void UniversalTM::initialize(const std::string &input)
{
    std::string delim_double = "11", delim_triple = "111";

    // seperate machine from word (separated by 111)
    size_t pos_triple = input.find(delim_triple);
    std::string machine = input.substr(0, pos_triple);
    std::string word = input.substr(pos_triple + delim_triple.length(), machine.length());

    for (char c : word)
    {
        tape.push_back(c);
    }

    size_t pos = 0;
    std::string token;

    // parse each transition
    while ((pos = machine.find(delim_double)) != std::string::npos)
    {
        parseTransition(machine.substr(0, pos));
        machine.erase(0, pos + delim_double.length());
    }
    parseTransition(machine);
}

void UniversalTM::printTape()
{
    for (int i = 0; i < tape.size(); i++)
    {
        if (head == i)
        {
            std::cout << "▼ " << "(q" + std::to_string(currentState) + ")";
        }
        std::cout << ' ';
    }

    std::cout << std::endl;

    for (char c : tape)
    {
        std::cout << c;
    }
    std::cout << std::endl;
}

char UniversalTM::read()
{
    return tape[head];
}

void UniversalTM::write(char &c)
{
    tape[head] = c;
}

void UniversalTM::goLeft()
{
    if (head == 0)
    {
        tape.push_front('_');
        return;
    }

    head--;
}

void UniversalTM::goRight()
{
    if ((head + 1) == tape.size())
    {
        tape.push_back('_');
    }

    head++;
}

std::vector<Transition> UniversalTM::getTransitions()
{
    return transitions;
}

void UniversalTM::setCurrentState(uint &stateNumber)
{
    currentState = stateNumber;
}

uint UniversalTM::getCurrentState()
{
    return currentState;
}
