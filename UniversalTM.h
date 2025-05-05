#include <string>
#include <vector>
#include <deque>

#ifndef UNIVERSALTM_H
#define UNIVERSALTM_H

typedef unsigned int uint;

enum class Direction
{
    Left,
    Right
};

struct Transition
{
    uint state, nextState;
    char symbolToRead, symbolToWrite;
    Direction direction;
};

extern const std::vector<char> SYMBOL_MAP;
extern const std::vector<Direction> DIRECTION_MAP;

class UniversalTM
{
private:
    std::deque<char> tape;
    size_t head;
    uint currentState;
    std::vector<Transition> transitions;
    void parseTransition(const std::string &code);

public:
    UniversalTM() : head(0), currentState(1) {}
    void initialize(const std::string &input);
    void printTape();
    char read();
    void write(char &c);
    void goLeft();
    void goRight();
    std::vector<Transition> getTransitions();
    void setCurrentState(uint &stateNumber);
    uint getCurrentState();
};

#endif
