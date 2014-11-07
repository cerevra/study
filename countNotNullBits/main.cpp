#include <iostream>

using namespace std;

short countNotNulls(int value){
    int count = 0;
    while(value){
        if (value & 0x01)
            ++count;
        value = value >> 1;
    }
    return count;
}

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
