#include "lcm.h"



Lcm::Lcm(const uint64_t max, const uint64_t threads)
    : m_impl(new LcmPrivate(max, threads))
{
}

Lcm::~Lcm()
{
    delete m_impl;
}

void Lcm::exec()
{
    m_impl->exec();
}

const Multipliers &Lcm::multipliers() const
{
    return m_impl->multipliers();
}
