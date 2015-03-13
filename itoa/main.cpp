#include <iostream>
#include <iomanip>

#include "countNotNullBits.h"

using namespace std;

char alph[] = {'0', '1', '2', '3',
               '4', '5', '6', '7',
               '8', '9', 'A', 'B',
               'C', 'D', 'E', 'F'};

inline bool isBaseTrivial (int base) {
    base -= 1;
    while (base & 1)
        base >>= 1;

    return base == 0;
}

// Только для демонстрации разных подходов
string intTrivialBase(unsigned int val, int base) {
    string result;

    static const char intBits = sizeof(int)*8;

    int modifedBase = base - 1;
    int baseBits    = countNotNulls(modifedBase);
    int resultSize  = 0;

    if (val & (1 << (intBits - 1)))
        resultSize = float(intBits)/baseBits + 0.9;
    else {
        unsigned int tmpVal = val;
        while (tmpVal) {
            tmpVal >>= baseBits;
            ++resultSize;
        }
        if (!resultSize)
            resultSize = 1;
    }

    result.resize(resultSize, '0');
    for (int i = resultSize - 1; i >= 0 && val; --i) {
        result[i] = alph[val & modifedBase];
        val >>= baseBits;
    }

    return result;
}

string intNonTrivialBase(int val, int base) {
    string result;

    unsigned int uVal = val;
    bool         neg  = false;

    if (base == 10)
        if (val < 0) {
            neg  = true;
            uVal = -1*val;
        }

    while (uVal) {
        result.push_back(alph[uVal % base]);
        uVal /= base;
    }

    if (base == 10 && neg)
        result.push_back('-');

    for (int l = 0, r = result.size() - 1; l < r; ++l, --r) {
        char tmp  = result[l];
        result[l] = result[r];
        result[r] = tmp;
    }

    return result;
}

string intToString(int val, int base) {
    if (base < 2 || base > 16)
        return string("not supported");

    if (isBaseTrivial(base))
        return intTrivialBase   (val, base);
    else
        return intNonTrivialBase(val, base);
}

int main()
{
    while (true){
        int val;
        cout << "Enter interger (dec): " << endl;
        cin >> val;

        for (int i = 2; i <= 16; ++i)
            cout << "Base " << setfill(' ') << setw(2) << i << " : "
                 << intToString(val, i) << endl;

        cout << "----" << endl << endl;
    }

    return 0;
}
