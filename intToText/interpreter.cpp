#include "interpreter.h"

Interpreter::Interpreter()
{
}

std::string Interpreter::text(long long num)
{
    std::string result;
    if (num < 0)
    {
        result.append("минус ");
        num *= -1;
    }
    else if (num == 0)
        return std::string("ноль");

    result.append(m_milliards.text(num));
    result.append(m_millions .text(num));
    result.append(m_thousands.text(num));
    result.append(m_ones     .text(num));

    return result;
}
