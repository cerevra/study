#include "threedigs.h"

ThreeDigs::ThreeDigs()
{
}

std::string ThreeDigs::text(long long &num){
    short int   curNum = currentNumber(num);
    std::string result;

    if (curNum)
    {
        result.append(hundreds(curNum));

        bool isOnes = false;
        result.append(decs    (curNum, isOnes));

        if (isOnes)
            result.append(ones(curNum));

        result.append(m_postfix);
        result.append(suffixOfPostfix(curNum));
    }

    return result;
}

const char* ThreeDigs::suffixOfPostfix(short cur)
{
    const char* result;
    switch (cur) {
    case 1: result = " "; break;
    case 2:
    case 3:
    case 4: result = "а "; break;
    default:result = "ов ";   break;
    }

    return result;
}

const char* ThreeDigs::one()
{
    return "один ";
}

const char* ThreeDigs::two()
{
    return "два ";
}

short ThreeDigs::currentNumber(long long& num)
{
    int cur = num/m_minLimit;

    if (cur)
        num = num%m_minLimit;

    return cur;
}

const char* ThreeDigs::hundreds(short& cur)
{
    const char* result;
    switch (cur/100) {
    case  1: result = "сто ";       break;
    case  2: result = "двести ";    break;
    case  3: result = "триста ";    break;
    case  4: result = "четыреста "; break;
    case  5: result = "пятьсот ";   break;
    case  6: result = "шестьсот ";  break;
    case  7: result = "семьсот ";   break;
    case  8: result = "восемьсот "; break;
    case  9: result = "девятьсот "; break;
    default: result = "";           break;
    }

    cur %= 100;

    return result;
}

const char* ThreeDigs::decs(short& cur, bool& isOnes)
{
    const char* result;
    short checkable;

    if (cur > 19){
        checkable = (cur/10)*10;
        isOnes    = true;
    }
    else
        checkable = cur;

    switch (checkable) {
    case 10: result = "десять ";       break;
    case 11: result = "одиннадцать ";  break;
    case 12: result = "двенадцать ";   break;
    case 13: result = "тринадцать ";   break;
    case 14: result = "четырнадцать "; break;
    case 15: result = "пятнадцать ";   break;
    case 16: result = "шестнадцать ";  break;
    case 17: result = "семнадцать ";   break;
    case 18: result = "восемнадцать "; break;
    case 19: result = "девятнадцать "; break;
    case 20: result = "двадцать ";     break;
    case 30: result = "тридцать ";     break;
    case 40: result = "сорок ";        break;
    case 50: result = "пятьдесят ";    break;
    case 60: result = "шестьдесят ";   break;
    case 70: result = "семдесят ";     break;
    case 80: result = "восемдесят ";   break;
    case 90: result = "девяносто ";    break;
    default: result = ""; isOnes = true; break;
    }

    return result;
}

const char* ThreeDigs::ones(short& cur)
{
    const char* result;
    cur %= 10;
    switch (cur) {
    case 1: result = one();     break;
    case 2: result = two();     break;
    case 3: result = "три ";    break;
    case 4: result = "четыре "; break;
    case 5: result = "пять ";   break;
    case 6: result = "шесть ";  break;
    case 7: result = "семь ";   break;
    case 8: result = "восемь "; break;
    case 9: result = "девять "; break;
    default:result = "";        break;
    }

    return result;
}


Ones::Ones()
{
    m_minLimit = 1;
    m_postfix  = "";
}

const char* Ones::one()
{
    return "одна ";
}

const char* Ones::two()
{
    return "две ";
}

const char* Ones::suffixOfPostfix(short)
{
    return "";
}


Thousands::Thousands()
{
    m_minLimit = 1000;
    m_postfix  = "тысяч";
}

const char* Thousands::suffixOfPostfix(short cur)
{
    const char* result;
    switch (cur) {
    case 1: result = "а "; break;
    case 2:
    case 3:
    case 4: result = "и "; break;
    default:result = " ";   break;
    }

    return result;
}

Millions::Millions()
{
    m_minLimit = 1000000;
    m_postfix  = "миллион";
}

Milliards::Milliards()
{
    m_minLimit = 1000000000;
    m_postfix  = "миллиард";
}
