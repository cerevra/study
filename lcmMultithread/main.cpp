#include <iostream>
#include <map>
#include <stdio.h>

#include "lcm.h"

using namespace std;

typedef map<uint64_t, uint64_t> Multipliers;

int main()
{
    const uint64_t maxNumber   = 10000;
    const uint16_t threadCount = 20;

    Lcm lcm (maxNumber, threadCount);

    lcm.exec();
    cout << "Less common multiple: " << endl;

    bool first = true;
    for (auto p : lcm.multipliers()){
        if (p.second > 0) {
            if (!first)
                cout << " * ";

            cout << p.first << "^" << p.second;
            first = false;
        }
    }
    cout << endl;

    return 0;
}
