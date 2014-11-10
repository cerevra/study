#include <iostream>
#include "countNotNullBits.h"

using namespace std;

char alph[] = {'0', '1', '2', '3',
               '4', '5', '6', '7',
               '8', '9', 'A', 'B',
               'C', 'D', 'E', 'F'};

string decToOther(int val, int base){
    string result;

    int baseBits    = countNotNulls(base - 1);
    int resultSize  = sizeof(int)*8.0/baseBits + 0.9;
    int modifedBase = base - 1;

    switch (base) {
    case  2:
    case  4:
    case  8:
    case 16:
        result.resize(resultSize, '0');
        for (int i = resultSize - 1; i >= 0; --i)
        {
            result[i] = alph[val & modifedBase];
            val >>= baseBits;
        }
        break;
    default:
        result = string("not supported");
        break;
    }

    return result;
}

int main()
{
    while (true){
        int val;
        cout << "Enter interger" << endl;
        cin >> val;
        cout << "Bin:" << decToOther(val,  2) << endl;
        cout << "Qud:" << decToOther(val,  4) << endl;
        cout << "Oct:" << decToOther(val,  8) << endl;
        cout << "Hex:" << decToOther(val, 16) << endl;
        cout << "----" << endl << endl;
    }

    return 0;
}
