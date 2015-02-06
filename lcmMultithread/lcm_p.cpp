#include "lcm_p.h"

#include <iostream>
#include <math.h>

#include "simplenumbers.h"

LcmPrivate::LcmPrivate(const uint64_t max, const uint64_t threads)
{
    Simples simp = simpleNumbs(max);

    for (auto x : simp){
        m_multipliers.emplace(x, 0);
    }

    m_threads.reserve(threads);
    for (uint16_t i = 0; i < threads; ++i){
        m_threads.emplace_back(this, m_multipliers, m_working);
    }
}

LcmPrivate::~LcmPrivate()
{
}

void LcmPrivate::exec()
{
    uint64_t num;

    while (scanf("%llu", &num) != EOF){
        if (num < 1)
            return;

        std::lock_guard<std::mutex> locker(m_mutex);
        m_queue.push(num);
    }

    while (m_working){
        int size;
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            size = m_queue.size();
        }

        if (size)
            std::this_thread::sleep_for(std::chrono::seconds(1));
        else
            m_working = false;
    }

    syncMultipliers();

    return;
}

bool LcmPrivate::next(uint64_t &num)
{
    std::lock_guard<std::mutex> locker(m_mutex);
    if (m_queue.size()){
        num = m_queue.front();
        m_queue.pop();
        return true;
    }
    else
        return false;
}

const Multipliers &LcmPrivate::multipliers() const
{
    return m_multipliers;
}

void LcmPrivate::syncMultipliers()
{
    for (auto& thr : m_threads) {
        const Multipliers& multi = thr.result();

        auto itThis = begin(m_multipliers);
        for (auto it = begin(multi); it != end(multi); ++it, ++itThis){
            if (itThis->second < it->second)
                itThis->second = it->second;
        }
    }
}

// Thread
LcmPrivate::Thread::Thread(LcmPrivate*        parent ,
                           const Multipliers& multi  ,
                           bool&              working)
    : m_multipliers(multi)
    , m_thread     (run, parent                 ,
                         std::ref(m_multipliers),
                         std::ref(working      ))
{
}

inline const Multipliers &LcmPrivate::Thread::result()
{
    m_thread.join();
    return m_multipliers;
}

void LcmPrivate::Thread::run(LcmPrivate*  parent ,
                             Multipliers& multi  ,
                             bool&        working)
{
    uint64_t num;

    while (working) {
        if (parent->next(num))
            factorization(multi, num);
        else
            std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void LcmPrivate::Thread::factorization(Multipliers &multi, uint64_t num)
{
    uint64_t sqrtNum = sqrt(num);

    for (auto it = begin(multi); num > 1 && it->first <= sqrtNum; ++it){
        uint64_t exponent = 0;

        while (num % it->first == 0){
            ++exponent;
            num /= it->first;
        }

        if (it->second < exponent)
            it->second = exponent;
    }

    if (num > 1){
        auto iterNum = multi.find(num);
        if (iterNum == multi.end())
            throw;

        if (!iterNum->second)
             iterNum->second = 1;
    }
}
