#ifndef LCMPRIVATE_H
#define LCMPRIVATE_H

#include <cstdint>
#include <vector>
#include <queue>
#include <mutex>
#include <map>
#include <thread>

typedef std::map<uint64_t, uint64_t> Multipliers;

class LcmPrivate
{
public:
    LcmPrivate(const uint64_t max, const uint64_t threads);
    ~LcmPrivate();

    void               exec       ();
    bool               next       (uint64_t& num);

    const Multipliers& multipliers() const;

private:
    void syncMultipliers();

    class Thread {
    public:
        Thread(LcmPrivate *parent, const Multipliers& multi, bool& working);

        const Multipliers& result();

        static void run(LcmPrivate *parent, Multipliers& multi, bool& working);
        static void factorization(Multipliers& multi, uint64_t num);

    private:
        Multipliers m_multipliers;
        std::thread m_thread;
    };

    typedef std::vector<Thread> Treads;

    Treads m_threads;
    bool   m_working = true;

    std::queue<uint64_t> m_queue;
    std::mutex           m_mutex;
    Multipliers          m_multipliers;
};

#endif // LCMPRIVATE_H
