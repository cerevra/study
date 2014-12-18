#include <iostream>

#include "balancer.h"

using namespace std;

int main()
{
    while (true){
        cout << "Enter weights (finish with -1): ";

        Balancer balance;
        int x;
        while (cin >> x){
            if (x < 0)
                break;
            balance.push_back(x);
        }

        cout << balance.calc().data() << endl;
    }

    return 0;
}
