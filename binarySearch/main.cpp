#include <iostream>

using namespace std;

class BinaryFinder{
public:
    int binarySearch(int value, int* arr, int size){

        m_value = value;
        m_arr   = arr;

        return binarySearch(0, size-1);
    }

private:
    int binarySearch(int startIdx, int endIdx){
        if (endIdx - startIdx < 0)
            return -1;

        int midIdx = (startIdx + endIdx)/2;

        if (m_arr[midIdx] == m_value)
            return midIdx;
        else if(m_arr[midIdx] < m_value)
            return binarySearch(midIdx + 1, endIdx    );
        else
            return binarySearch(startIdx  , midIdx - 1);
    }

    int  m_value;
    int* m_arr;
};

int main()
{
    int size = 0;
    cout << "Enter array size" << endl;
    cin >> size;

    int *arr = new int[size];
    cout << "Enter array" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> *(arr + i);
    }

    int valToFind;
    cout << "Enter value to find" << endl;
    cin >> valToFind;

    BinaryFinder bf;
    cout << bf.binarySearch(valToFind, arr, size) << endl;

    return 0;
}
