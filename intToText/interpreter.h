#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "threedigs.h"

class Interpreter
{
public:
    Interpreter();

    std::string text(long long num);

private:
    Ones      m_ones;
    Thousands m_thousands;
    Millions  m_millions;
    Milliards m_milliards;
};

#endif // INTERPRETER_H
