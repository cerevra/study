#ifndef LCM_H
#define LCM_H

#include "lcm_p.h"

class Lcm
{
public:
    Lcm(const uint64_t max, const uint64_t threads);
    ~Lcm();

    void               exec       ();
    const Multipliers& multipliers() const;

private:
    LcmPrivate* m_impl;
};

#endif // LCM_H
