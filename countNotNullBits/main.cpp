#include <iostream>
#include "countNotNullBits.h"

using namespace std;

int main()
{
    while (true) {
        int value = 0;
        cout << "Enter integer" << endl;
        cin >> value;

        cout << countNotNulls(value) << endl;
    }

    return 0;
}
