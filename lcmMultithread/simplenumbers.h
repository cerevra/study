#ifndef SIMPLENUMBERS
#define SIMPLENUMBERS

#include <cstdint>
#include <vector>

typedef std::vector<uint64_t> Simples;

// Решето Эратосфена
Simples simpleNumbs(const uint64_t maxNumber){
    Simples simp;

    if (maxNumber < 2)
        return simp;

    simp .reserve(maxNumber/5);

    typedef std::vector<bool> Sieve;

    Sieve sieve;
    sieve.resize (maxNumber + 1, true);
    sieve [0] = sieve[1] = false;

    for (uint64_t i = 2; i <= maxNumber; ++i){
        if (sieve[i]){
            simp.push_back(i);

            for (uint64_t k = i; k <= maxNumber; k += i)
                sieve[k] = false;
        }
    }

    return simp;
}

#endif // SIMPLENUMBERS
