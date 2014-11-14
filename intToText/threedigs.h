#ifndef THREEDIGS_H
#define THREEDIGS_H

#include <string>

class Ones;
class Thousands;
class Millions;
class Milliards;

class ThreeDigs
{
public:
    std::string text(long long &num);

protected:
    virtual const char* suffixOfPostfix(short cur);
    virtual const char* one            ();
    virtual const char* two            ();

    long long   m_minLimit;
    const char* m_postfix;

private:
    friend class Ones;
    friend class Thousands;
    friend class Millions;
    friend class Milliards;
    ThreeDigs();

    short       currentNumber(long long &num);
    const char* hundreds     (short int& cur);
    const char* decs         (short int& cur, bool& isOnes);
    const char* ones         (short int& cur);
};

class Ones : public ThreeDigs {
public:
    Ones();

private:
    const char* one  ();
    const char* two  ();

    const char* suffixOfPostfix(short);
};

class Thousands : public ThreeDigs {
public:
    Thousands();

private:
    const char* suffixOfPostfix(short cur);
};

class Millions : public ThreeDigs {
public:
    Millions();
};

class Milliards : public ThreeDigs {
public:
    Milliards();
};

#endif // THREEDIGS_H
