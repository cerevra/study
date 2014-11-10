#include <iostream>

using namespace std;

int findSingle(int* arr, int size){
    int val = 0;

    for (int i = 0; i < size; ++i){
        val ^= arr[i];
    }

    return val;
}

int main()
{
    while (true){
        int size = 0;
        cout << "Enter size of array (odd): ";
        cin >> size;

        if (size < 1)
            continue;

        int* arr = new int[size];
        cout << "Enter array" << endl;
        for (int i = 0; i < size; ++i)
            cin >> *(arr + i);

        cout << "Value of Single: " << findSingle(arr, size) << endl << endl;
    }

    return 0;
}
